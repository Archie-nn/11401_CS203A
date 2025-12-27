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

