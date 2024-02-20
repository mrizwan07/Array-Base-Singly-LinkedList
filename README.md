# Advanced Linked List with Static Memory Allocation

This is Array based implementation of linked list using static memory allocation. The list supports insertion, deletion, and display operations efficiently.

## Overview

### `Node` Struct

- Represents a node in the linked list.
- Contains:
  - Generic data type `T`.
  - Pointer `next` to the next node.
- Methods:
  - Default constructor initializes `next` to -1.
  - Parameterized constructor sets `info` and initializes `next` to -1.

### `ALSLL` Class (Advanced Linked List with Static Memory Allocation)

- Represents the advanced linked list.
- Features:
  - Array `data` to hold nodes.
  - Integer `size` for list size.
  - Integer `SLH` (System List Head) for memory allocation.
  - Integer `ULH` (User List Head) for list traversal.
- Methods:
  - `getNewNode`: Fetches a new node from the system list.
  - `initializer`: Initializes the system list.
  - `insertAtHead`: Inserts a node at the list's head.
  - `displayALSLL`: Displays list elements.
  - `insertAtTail`: Inserts a node at the list's tail.
  - `remove`: Deletes a node with a specified key.
  - `removeAfter`: Deletes the node following a given key.
  - `removeBefore`: Deletes the node preceding a specified key.

## Example Usage

```cpp
int main()
{
    ALSLL<int> list;
    list.insertAtHead(5).insertAtHead(4).insertAtHead(3).insertAtHead(2).insertAtHead(1).insertAtTail(6);
    list.displayALSLL();
    return 0;
}
