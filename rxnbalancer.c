#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
/****************************************************************************
  @desc   Print each string in an array of strings
  @author Brenton Bongcaron brenton3926@gmail.com
  @param  char** components     --> array of pointers to strings
          int numComponents     --> number of pointers to strings in the array
*****************************************************************************/
void printComponents(char** components, int numComponents);

/****************************************************************************
  @desc   Free a malloc'ed array of char strings
  @author Brenton Bongcaron brenton3926@gmail.com
  @param  char** matrix         --> malloc'ed matrix to be freed
          int numElements       --> number of pointers to arrays in the array
*****************************************************************************/
void freeMatrix(char** matrix, int numElements);

/****************************************************************************
  @file   rxnbalancer.c
  @desc   This function will take a chemical equation(s) without stoichiometric
          coefficients and balance it.
  @author Brenton Bongcaron brenton3926@gmail.com
  @param  a chemical equation without stoichiometric coefficents, using =
          instead of the standard arrow (-->) in the form of a string OR a
          file containing multiple chemical equations in the above format.
  @return prints balanced chemical equation(s) in terminal
*****************************************************************************/
int main()
{

  char equation[200];
  printf("Enter an equation OR file name\n");
  scanf("%s\n", equation);
  printf("You entered : %s\n", equation);

  //printf("numReactants = %d\n", numReactants);
  //printComponents(reactants, numReactants);


  /* Free the malloc'ed component matrices */
  //freeMatrix(reactants, numReactants);
  //freeMatrix(products, numProducts);

  return 0;
}

void printComponents(char** components, int numComponents)
{
    for (int i = 0; i < numComponents; i++)
    {
      printf("Component %d: %s\n", i + 1, components[i]);
    }
    return;
}

void freeMatrix(char** matrix, int numElements)
{
  for (int i = 0; i < numElements; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
  return;
}
