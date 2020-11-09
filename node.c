#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
  return;
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

void printList(Node** head){
  Node* ptr = *head;
  while (ptr)
  {
    printf("%s -> ", ptr->compound);
    ptr = ptr->next;
  }
  printf("null\n");
  return;
}

void freeList(Node** head)
{
  Node* ptr = *head;
  Node* prev = NULL;
  while (ptr)
  {
    prev = ptr;
    ptr = ptr->next;
    free(prev->compound);
    free(prev);
  }
  return;
}
