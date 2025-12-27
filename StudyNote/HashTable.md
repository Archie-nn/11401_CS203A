# Study Note: Hash Table

## Description

Hash Table: A key–value data structure that uses a **hash function** to map each key to an index in an underlying array. With a good hash function and controlled **load factor**, hash tables provide **expected \(O(1)\)** time for lookup, insertion, and deletion; however, collisions can occur and are handled via **separate chaining** (lists per bucket) or **open addressing** (probing). In the worst case (many collisions), operations can degrade to **\(O(n)\)**, but in practice hash tables are widely used for fast membership tests and key-based retrieval.

## Visualization

![Hash Table](./hashtable.png)

## Abstract Data Type

A hash table is an abstract data type (ADT) that represents a **key–value map**. It uses a **hash function** to translate a key into a bucket/index and resolves collisions (e.g., by separate chaining or open addressing). The hash table ADT supports the following operations:

- **Insert / Put**: Add a new `(key, value)` pair. If `key` already exists, update its value. Expected time complexity: \(O(1)\); worst case: \(O(n)\).
- **Lookup / Get**: Retrieve the value associated with `key` (or report not found). Expected time complexity: \(O(1)\); worst case: \(O(n)\).
- **Update**: Modify the value of an existing `key`. Expected time complexity: \(O(1)\); worst case: \(O(n)\).
- **Delete / Remove**: Remove the entry for `key` if present. Expected time complexity: \(O(1)\); worst case: \(O(n)\).
- **Contains**: Test whether a `key` exists. Expected time complexity: \(O(1)\); worst case: \(O(n)\).
- **Traversal / Iteration**: Visit all stored `(key, value)` entries (order unspecified). Time complexity: \(O(n)\).
- **Resize / Rehash**: Rebuild the table with a new capacity to keep the load factor bounded. Time complexity: \(O(n)\).

Hash tables are widely used due to their fast expected performance for key-based retrieval and updates.

## Hash Function Design

A **hash function** maps a key to an array index:


### Goals of a Good Hash Function

| Goal | Meaning |
|----|--------|
| Determinism | Same key always maps to the same index |
| Uniformity | Keys are evenly distributed |
| Efficiency | Fast to compute |
| Low Correlation | Small input change → large hash change |

---

### Common Hashing Techniques

| Key Type | Method | Description |
|-------|-------|------------|
| Integer | Modulo hashing | `h(x) = x mod m` (choose `m` carefully) |
| Integer | Multiplicative hashing | Multiply by constant, take high bits |
| String | Polynomial rolling hash | Combines characters using powers |

---

### Choosing Table Size `m`

| Strategy | Common Choice |
|--------|--------------|
| Separate chaining | Prime number |
| Open addressing | Power of two (needs good bit mixing) |

---

## Separate Chaining:Collision Resolution Strategies

Each table slot stores a **bucket** (usually a linked list).

### Properties

| Aspect | Description |
|----|------------|
| Insert | Add to bucket |
| Search / Delete | Scan bucket |
| Expected time | O(1 + α) |
| Deletion | Simple |

### Pros / Cons

| Pros | Cons |
|----|----|
| Handles high load factor well | Extra memory for pointers |
| Easy deletion | Worse cache locality |

## Open Addressing:Collision Resolution Strategies


All elements are stored **directly in the array**.  
Collisions are resolved by **probing**.

### Probing Methods Comparison

| Method | Probe Pattern | Advantages | Drawbacks |
|-----|-------------|-----------|----------|
| Linear Probing | `i, i+1, i+2...` | Simple, cache-friendly | Primary clustering |
| Quadratic Probing | `i+1², i+2²...` | Less primary clustering | Secondary clustering |
| Double Hashing | `i + k·h₂(key)` | Best distribution | More computation |

---

### Clustering Summary

| Type | Cause | Occurs In |
|----|-----|----------|
| Primary clustering | Long contiguous runs | Linear probing |
| Secondary clustering | Same probe sequence | Quadratic probing |
| Minimal clustering | Different step sizes | Double hashing |

---

### Deletion in Open Addressing

- Uses **tombstones** to preserve probe chains
- Table must occasionally be rehashed

### Load Factor Guidelines

| Strategy | Recommended α |
|-------|---------------|
| Separate chaining | Can exceed 1 |
| Open addressing | Keep α < 0.7 |

---

## Practical Guidelines

- Use a **well-mixed hash function**
- Keep load factor under control
- Prefer **double hashing** when probe length matters
- Rehash when performance degrades

## Conclusion: Open Addressing vs Separate Chaining

Both **Open Addressing** and **Separate Chaining** are effective collision resolution strategies for hash tables.  
They achieve similar *average-case* performance, but differ significantly in **memory usage, cache behavior, and practical trade-offs**.

## Time Complexity Comparison

| Operation | Separate Chaining | Open Addressing |
|--------|------------------|----------------|
| Insert (expected) | O(1 + α) | O(1) (under safe load factor) |
| Lookup (expected) | O(1 + α) | O(1) |
| Delete (expected) | O(1 + α) | O(1) (with tombstones) |
| Worst case | O(n) | O(n) |
| Resize / Rehash | O(n) (amortized O(1)) | O(n) (amortized O(1)) |

---

## Space Complexity Comparison

| Aspect | Separate Chaining | Open Addressing |
|-----|------------------|----------------|
| Table storage | O(m) buckets | O(m) slots |
| Extra memory | Pointers / node objects | None |
| Total space | O(m + n) | O(m) ≈ O(n) |
| Cache locality | Poorer | Better |

---

## Typical Applications

| Use Case | Preferred Strategy | Reason |
|-------|------------------|-------|
| Language runtimes (e.g., Python dict) | Open addressing | Cache-friendly, fast lookups |
| In-memory key-value stores | Open addressing | High performance, low overhead |
| Systems with frequent deletions | Separate chaining | Simple and reliable deletion |
| Hash tables with unknown growth | Separate chaining | Handles high load factor well |
| Educational / simple implementations | Separate chaining | Easier to implement |

---

## Final Takeaway

- **Separate Chaining** is more robust and easier to manage, especially when deletions are frequent or load factor is unpredictable.
- **Open Addressing** is more memory-efficient and faster in practice, but requires careful control of the load factor and hash quality.

In modern systems, **open addressing** is often preferred for performance-critical workloads, while **separate chaining** remains a solid choice for simplicity and flexibility.
