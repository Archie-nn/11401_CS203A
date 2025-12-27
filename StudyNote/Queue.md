# Study Note: Queue

## Description
- A linear data structure that operates on the First-In-First-Out (FIFO) principle.
- Elements are added at one end, called the "rear," and removed from the other end, called the "front."
- Comparable to a line of people waiting, where the first person in line is served first.
- Common operations:
    - **Enqueue**: Add an element to the rear.
    - **Dequeue**: Remove an element from the front.

## Visualization
![Queue](./queue.png)

## Abstract Data Type
A queue is an abstract data type (ADT) that stores a collection of elements with two ends: **rear** (insertion) and **front** (removal). It follows the **First-In-First-Out (FIFO)** rule: the earliest inserted element is the first one removed.

The queue ADT supports the following operations:

- **Create**: Initialize an empty queue. Time complexity: \(O(1)\).
- **Enqueue**: Insert an element at the rear. Time complexity: \(O(1)\) (amortized \(O(1)\) for dynamic arrays).
- **Dequeue**: Remove and return the front element (underflow if empty). Time complexity: \(O(1)\).
- **Front / Peek**: Return (without removing) the front element (error if empty). Time complexity: \(O(1)\).
- **isEmpty**: Check whether the queue contains no elements. Time complexity: \(O(1)\).
- **Size**: Return the number of elements (if maintained). Time complexity: \(O(1)\) (otherwise \(O(n)\)).

**FIFO property**:
- If `x` is enqueued before `y`, then `x` is dequeued before `y`.

## Implementation
- **Array-based**
- Queue: typically use a **circular array** with indices `front` and `rear` to support O(1) enqueue/dequeue.
- **Linked-list-based**
- Queue: maintain both head (front) and tail (rear) pointers for O(1) enqueue/dequeue.

## Complexity

### Time Complexity

| ADT Operation | Array-based (circular) | Linked-list-based |
|---|---:|---:|
| `Enqueue` | **O(1)** (fixed capacity; may overflow if full) / Amortized **O(1)** (dynamic; worst-case **O(n)** on resize) | **O(1)** (with tail pointer) |
| `Dequeue` | **O(1)** (may underflow if empty) | **O(1)** (with head pointer; may underflow if empty) |
| `Front` / `Peek` | **O(1)** (error/underflow if empty) | **O(1)** (error/underflow if empty) |
| `isEmpty` | **O(1)** | **O(1)** |
| `Size` | **O(1)** (if maintained) | **O(1)** (if maintained; otherwise **O(n)**) |

### Space Complexity
- **Array-based (circular)**
    - **O(n)** elements stored.
    - **Fixed capacity**: **O(C)**.
    - **Dynamic array**: **O(C)** with `C = Θ(n)` plus possible unused capacity.
- **Linked-list-based**
    - **O(n)** nodes.
    - Per-node pointer overhead (typically one `next` pointer), plus **O(1)** for head/tail pointers.
 
| Aspect | Array-based Queue | Linked-list-based Queue |
|-----|------------------|------------------------|
| Element Storage | O(n) | O(n) |
| Extra Overhead | Possible unused capacity | Pointer(s) per node |
| Memory Layout | Contiguous | Non-contiguous |
| Overall Space | O(n) | O(n) |

## Variations
- **Circular queue (ring buffer)**: Array-based queue with wraparound indices to avoid shifting.
- **Deque (double-ended queue)**: Insert/remove at both front and rear in **O(1)**.
- **Priority queue**: Removes highest/lowest priority element first (often heap-based; ops typically **O(log n)**).
- **Bounded queue**: Fixed capacity; enqueue may overflow.
- **Blocking queue**: `enqueue`/`dequeue` may block until space/data is available (common in producer–consumer).
- **Queue via two stacks**: Implements FIFO using two LIFO stacks (amortized **O(1)** per operation).
- **Monotonic queue**: Maintains a monotone order; used for sliding window min/max in **O(n)** total.

## Practical Trade-offs

### Array-based Queue
**Advantages**
- Better cache locality
- Simple and fast with circular array
- Lower per-element memory overhead

**Disadvantages**
- Resizing cost
- Fixed maximum size unless dynamic resizing is used

---

### Linked-list-based Queue
**Advantages**
- Dynamic size (no capacity limit)
- No resizing overhead
- Stable O(1) enqueue and dequeue

**Disadvantages**
- Extra memory for pointers
- Poorer cache performance

---

## Typical Applications of Queues

| Application | Why Queue is Suitable |
|-----------|----------------------|
| CPU scheduling | Processes are handled in arrival order |
| Task scheduling systems | Jobs are executed FIFO |
| Breadth-First Search (BFS) | Nodes are visited level by level |
| Print queue | Documents are printed in order |
| Message buffering | Data processed in arrival order |
| I/O buffering | Smooths data transfer rates |

---

## Conclusion

Both array-based and linked-list-based queues efficiently support FIFO operations with O(1) enqueue and dequeue.

An **array-based queue** is preferred when:
- The maximum queue size is predictable
- Cache efficiency and memory locality are important
- A circular buffer can be used

A **linked-list-based queue** is preferred when:
- Queue size is highly dynamic
- Resizing overhead must be avoided
- Memory fragmentation is not a concern

In practice, array-based queues are commonly used for fixed-size or high-performance systems, while linked-list-based queues are chosen for flexible, dynamically sized workloads.
