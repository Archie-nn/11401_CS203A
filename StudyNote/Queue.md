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
