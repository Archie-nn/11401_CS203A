# Study Note: Linked List

## Description  

Linked List: A linked list is a sequence of nodes stored in non-contiguously memory. Each node contains a value field and a pointer field that links to the next node. Traversal is sequential O(n), but insertion or deletion (given a node) is O(1).

## Visualization

![Linked List](./linkedlist.png)

## Abstract Data Type

A linked list can be represented as an Abstract Data Type (ADT) with the following operations:

- **Create**: Initialize an empty linked list.
- **Insert**: Add a new node with a given value at a specific position.
- **Delete**: Remove a node at a specific position.
- **Search**: Find a node containing a specific value.
- **Traverse**: Visit each node in the linked list sequentially.
- **Update**: Modify the value of a node at a specific position.

These operations allow for dynamic memory usage and efficient insertion/deletion compared to arrays.

---

## Time Complexity

Let `n` be the number of nodes in the linked list.

### Basic Operations

| Operation | Description | Time Complexity |
|---------|------------|----------------|
| Access / Traverse (by index) | Walk node-by-node from head | O(n) |
| Search (by value) | Linear scan | O(n) |
| Update (by index) | Traverse to node then update | O(n) |

---

### Insert

| Insertion Type | Condition | Time Complexity |
|--------------|----------|----------------|
| At head | Direct insertion | O(1) |
| At tail | Tail pointer maintained | O(1) |
| At tail | No tail pointer | O(n) |
| At position / after given node | Locate position then relink | O(n) + O(1) |

---

### Delete

| Deletion Type | Condition | Time Complexity |
|--------------|----------|----------------|
| At head | Direct removal | O(1) |
| Given node (or predecessor known) | Direct unlink | O(1) |
| By value / at position | Locate node then unlink | O(n) + O(1) |

---

## Space Complexity

| Item | Space Complexity | Description |
|----|-----------------|------------|
| Node Storage | O(n) | Space for `n` nodes |
| Per-node Overhead | O(1) | Pointer(s): `next` (singly), `prev + next` (doubly) |
| Auxiliary Space (iterative) | O(1) | No extra memory needed |
| Auxiliary Space (recursive traversal) | O(n) | Call stack usage |

---

## Conclusion

Linked lists provide efficient insertion and deletion operations, especially at the head or when the target node is already known, achieving O(1) time complexity in these cases.

However, linked lists do not support random access. Operations such as access, search, or update by index require linear traversal from the head, resulting in O(n) time complexity.

Linked lists are well-suited for applications where frequent insertions and deletions are required and random access is not critical. In contrast, arrays are more suitable for read-heavy workloads that require fast index-based access.

---

