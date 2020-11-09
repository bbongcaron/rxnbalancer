#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

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
  scanf("%s\n", equation);
  printf("You entered : %s\n", equation);

  Node* reactants = NULL;
  insert(&reactants, equation);
  printList(&reactants);
  printf("numNodes = %d\n", listLength(&reactants));

  return 0;
}
