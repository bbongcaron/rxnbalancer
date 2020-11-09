#ifndef NODE_H
#define NODE_H

  int add(int, int);

  typedef struct Node{
    struct Node* next;
    char* compound;
  } Node;


#endif
