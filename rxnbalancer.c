#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

void getComponents(Node** reactants, Node** products, char* equation);
/****************************************************************************
  @file   rxnbalancer.c
  @desc   This function will take a chemical equation(s) via stdin without
          stoichiometric coefficients and balance it.
  @author Brenton Bongcaron brenton3926@gmail.com
  @output prints balanced chemical equation(s) in terminal
*****************************************************************************/
int main()
{

  char equation[200];
  printf("Enter an equation OR file name\n");
  gets(equation);

  Node* reactants = NULL;
  Node* products = NULL;
  getComponents(&reactants, &products, equation);
  printf("Reactants Linked List: \t");
  printList(&reactants);

  printf("Reactants Linked List: \t");
  printList(&products);
  
  freeList(&reactants);
  freeList(&products);
  return 0;
}

void getComponents(Node** reactants, Node** products, char* equation)
{
  bool onProdSide = 0;
  char* token = strtok(equation, " ");
  while(token)
  {
    if (strcmp(token, "-->") == 0)
    {
      onProdSide = 1;
    }
    else if (strcmp(token, "+") != 0){
      if (onProdSide)
      {
        insert(products, token);
      }
      else
      {
        insert(reactants, token);
      }
    }
    token = strtok(NULL, " ");
  }
  printf("\n");
}
