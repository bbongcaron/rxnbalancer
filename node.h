#ifndef NODE_H
#define NODE_H

  typedef struct Node{
    struct Node* next;
    char* compound;
  } Node;

  /* inserts Node for newCompound into linked list */
  void insert(Node**, char*);
  /* determines the number of nodes in a linked list */
  int listLength(Node**);
  /* prints the linked list */
  void printList(Node**);
#endif
