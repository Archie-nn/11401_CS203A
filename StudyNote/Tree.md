# Study Note: Tree

## Description

A Tree is a non-linear hierarchical data structure consisting of connected nodes without cycles. Each node may have zero or more children, forming parent–child relationships, and the entire structure represents hierarchical data (file systems, organization charts, decision models).

## Visualization

![Tree](./tree.png)

## Abstract Data Type

**Binary Tree Operations:**
- `Create()`: create an empty binary tree
- `IsEmpty(bt)`: true if bt is empty
- `MakeBT(bt1, item, bt2)`: construct a new binary tree with left subtree bt1, item as root, right subtree bt2
- `Lchild(bt)`: return left subtree
- `Rchild(bt)`: return right subtree
- `Data(bt)`: return item at root

**Implementation Approaches:**
1. **Pointer-based representation** (common for BST)
2. **Array-based representation** (heaps, complete trees)
3. **Left Child–Right Sibling Representation** (general trees)

**Traversal Algorithms:**
- Preorder (root-left-right)
- Inorder (left-root-right)
- Postorder (left-right-root)
- Level-order (BFS with queue)
