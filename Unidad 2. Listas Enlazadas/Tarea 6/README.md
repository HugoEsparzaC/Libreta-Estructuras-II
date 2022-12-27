[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9514048)
# Doubly Linked List with Sentinel

If you need help running the tests or submitting your code, check out `HELP.md`.

## Instructions

Implement a doubly linked list with sentinel.

Like an array, a linked list is a simple linear data structure. Several
common data types can be implemented using linked lists, like queues,
stacks, and associative arrays.

A linked list is a collection of data elements called *nodes*. In a
*singly linked list* each node holds a value and a link to the next node.
In a *doubly linked list* each node also holds a link to the previous
node.

A *sentinel* is a dummy node that allow us to simplify boundary conditions.
In linked list the sentinel is a node that represents `NULL` but has all
other attibutes of the other nodes in the list. References to `NULL` are
replaced by references to the sentinel. The sentinel lies between the head
and the tail.

You will write an implementation of a doubly linked list. Implement a
Node to hold a value and pointers to the next and previous nodes. Then
implement a List which holds references to the first and last node and
offers an array-like interface for adding and removing items:

* `push_back` (*insert value at back*);
* `pop_back` (*remove value at back*);
* `push_front` (*insert value at front*);
* `pop_front` (*remove value at front*);

Also getting the first and last items in the list:
* `front` (*gets the value at front*);
* `back` (*gets the value at back*);

With additional operations to reverse and sort the contents of the list:
* `reverse` (*reverses the order of the elements in the list*);
* `sort` (*sorts the elements in the list*);

To keep your implementation simple, the tests will not cover error
conditions. Specifically: `front` or `back` will never be called on an
empty list.

If you want to know more about linked lists, check [Wikipedia](https://en.wikipedia.org/wiki/Linked_list).

## Source

### Created by

- @wolf99

### Contributed to by

- @patricksjackson
- @QLaille
- @ryanplusplus
- @siebenschlaefer

### Modified by

- @eloyhz

### Based on

Classic computer science topic