# Study Note: Stack

## Description
- A linear data structure that operates on the Last-In-First-Out (LIFO) or First-In-Last-Out (FILO) principle.
- Elements are added and removed from the same end, referred to as the "top."
- Similar to a stack of plates, where you can only add or remove plates from the top.
- Common operations:
    - **Push**: Add an element to the top.
    - **Pop**: Remove the top element.
---

 ## Visualization
![Stack](./stack.webp)

## Abstract Data Type

A stack is an abstract data type (ADT) that stores a collection of elements with a single accessible end called the **top**. It follows the **Last-In-First-Out (LIFO)** rule: the most recently inserted element is the first one removed.

The stack ADT supports the following operations:

- **Create**: Initialize an empty stack. Time complexity: \(O(1)\).
- **Push**: Insert an element onto the top. Time complexity: \(O(1)\) (amortized \(O(1)\) for dynamic arrays).
- **Pop**: Remove and return the top element (underflow if empty). Time complexity: \(O(1)\).
- **Top / Peek**: Return (without removing) the top element (error if empty). Time complexity: \(O(1)\).
- **isEmpty**: Check whether the stack contains no elements. Time complexity: \(O(1)\).
- **Size**: Return the number of elements (if maintained). Time complexity: \(O(1)\) (otherwise \(O(n)\)).

**LIFO property**:
- After `push(S, x)`, `top(S) = x`.
- If `S` is non-empty, `pop(S)` returns the most recently pushed element not yet popped.

  
## Implementation
- **Array-based**
- use an index `top` to track the current top element.
- **Linked-list-based**
- Stack: insert/remove at the head for O(1) push/pop.

## Complexity

### Time Complexity

| ADT Operation | Array-based (dynamic) | Array-based (fixed capacity) | Linked-list-based |
|---|---:|---:|---:|
| `Push` | Amortized **O(1)** (worst-case **O(n)** on resize) | **O(1)** (may overflow if full) | **O(1)** |
| `Pop` | **O(1)** (may underflow if empty) | **O(1)** (may underflow if empty) | **O(1)** (may underflow if empty) |
| `Top` / `Peek` | **O(1)** (error/underflow if empty) | **O(1)** (error/underflow if empty) | **O(1)** (error/underflow if empty) |
| `isEmpty` | **O(1)** | **O(1)** | **O(1)** |
| `Size` | **O(1)** (if maintained) | **O(1)** (if maintained) | **O(1)** (if maintained; otherwise **O(n)**) |

### Space Complexity

- **Array-based**
    - **O(n)** to store `n` elements.
    - **Fixed capacity**: **O(C)** where `C` is the array capacity (may be > `n`).
    - **Dynamic array**: **O(C)** with `C = Θ(n)` typically; may keep extra unused capacity.
- **Linked-list-based**
    - **O(n)** nodes.
    - Additional per-element pointer overhead (e.g., one `next` pointer per node).
| Aspect | Array-based Stack | Linked-list-based Stack |
|-----|------------------|------------------------|
| Element Storage | O(n) | O(n) |
| Extra Overhead | Possible unused capacity | Pointer(s) per node |
| Memory Layout | Contiguous | Non-contiguous |
| Overall Space | O(n) | O(n) |

## Variations
- **Array-based stack**: Uses a contiguous array and a `top` index (fast, cache-friendly).
- **Linked-list stack**: Each node points to the next (no fixed capacity; extra pointer overhead).
- **Bounded stack**: Fixed maximum size; `push` may overflow.
- **Dynamic stack**: Resizes backing array when needed; `push` is amortized **O(1)**.
- **Two stacks in one array**: Grow two stacks from opposite ends to share capacity efficiently.
- **Min/Max stack**: Supports `getMin()` / `getMax()` in **O(1)** using an auxiliary stack.
- **Monotonic stack**: Maintains increasing/decreasing order; used for “next greater/smaller element” problems.

## Practical Trade-offs

### Array-based Stack
**Advantages**
- Better cache locality
- Simple implementation
- Lower per-element memory overhead

**Disadvantages**
- Resizing cost
- Fixed capacity unless dynamic resizing is used

### Linked-list-based Stack
**Advantages**
- No capacity limit
- No resizing overhead
- Guaranteed O(1) push and pop

**Disadvantages**
- Extra memory for pointers
- Poorer cache performance

---

## Typical Applications of Stacks

| Application | Why Stack is Suitable |
|-----------|----------------------|
| Function call management (call stack) | Tracks active function calls using LIFO |
| Expression evaluation | Operators and operands processed in reverse order |
| Parenthesis matching | Last opened parenthesis must be closed first |
| Undo / Redo operations | Most recent action is reverted first |
| Depth-First Search (DFS) | Explores the most recent node first |
| Backtracking algorithms | Easily revert to previous states |

---

## Conclusion

Both array-based and linked-list-based stacks offer efficient O(1) push and pop operations, making them suitable for LIFO-based tasks.

An **array-based stack** is generally preferred when:
- The maximum size is known or predictable
- Memory efficiency and cache performance are important

A **linked-list-based stack** is preferred when:
- The stack size is highly dynamic
- Resizing overhead must be avoided

In practice, array-based stacks are more commonly used due to their simplicity and performance, while linked-list-based stacks are chosen when flexibility is critical.

---
