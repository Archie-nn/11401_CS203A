# Study Note: Stack

## Description
- A linear data structure that operates on the Last-In-First-Out (LIFO) or First-In-Last-Out (FILO) principle.
- Elements are added and removed from the same end, referred to as the "top."
- Similar to a stack of plates, where you can only add or remove plates from the top.
- Common operations:
    - **Push**: Add an element to the top.
    - **Pop**: Remove the top element.
    - **Top / Peek**: Return (without removing) the top element (error if empty). Time complexity: \(O(1)\).
    - **isEmpty**: Check whether the stack contains no elements. Time complexity: \(O(1)\).
    - **Size**: Return the number of elements (if maintained). Time complexity: \(O(1)\) (otherwise \(O(n)\)).

    - **LIFO property**:
    - After `push(S, x)`, `top(S) = x`.
    - If `S` is non-empty, `pop(S)` returns the most recently pushed element not yet popped.

---

 ## Visualization
![Stack](./stack.webp)
