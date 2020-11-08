#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  @return balanced chemical equation(s)
*****************************************************************************/
int main(int argc, char* argv[argc+1])
{
  int index = 1;
  int numReactants = 0;

  /* Count the number of reactants in the equation */
  while (strcmp(argv[index], "=") != 0 && index < (argc + 1))
  {
    if (strcmp(argv[index], "+") == 0)
    {
      index++;
      continue;
    }
    numReactants++;
    index++;
  }
  /*
    Opted for dyanmic allocation of array instead of linked list because it is
     preferred to have instant access to all components in the equation at a
     given moment.
  */

  index = 1;
  int reactantIndex = 0;
  // the array of reactants
  char** reactants = malloc(sizeof(char*) * numReactants);

  /* Insert each reactant into char** reactants */
  while (strcmp(argv[index], "=") != 0 && index < (argc + 1))
  {
    if (strcmp(argv[index], "+") == 0)
    {
      index++;
      continue;
    }
    reactants[reactantIndex] = malloc(sizeof(char) * strlen(argv[index]));
    strcpy(reactants[reactantIndex], argv[index]);
    reactantIndex++;
    index++;
  }
  // printComponents(reactants, numReactants);
  // Free the malloc'ed reactants matrix
  freeMatrix(reactants, numReactants);
  return 0;
}

void printComponents(char** components, int numComponents) {
    for (int i = 0; i < numComponents; i++)
    {
      printf("Component %d: %s\n", i, components[i]);
    }
    return;
}

void freeMatrix(char** matrix, int numElements){
  for (int i = 0; i < numElements; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
  return;
}
