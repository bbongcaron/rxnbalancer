#ifndef NODE_H
#define NODE_H

  int add(int, int);

  typedef struct Node{
    struct Node* next;
    char* compound;
  } Node;

  void insert(Node** head, char* newCompound)
  {
    Node* newNode = malloc(sizeof(Node));
    newNode->compound = malloc(sizeof(char) * strlen(newCompound));
    strcpy(newNode->compound, newCompound);
    newNode->next = *head;
    *head = newNode;
  }
  int listLength(Node** head)
  {
    Node* current = *head;
    if (!current)
    {
      return 0;
    }
    int numElements = 0;
    while (current)
    {
      current = current->next;
      numElements++;
    }

    return numElements;
  }
#endif
