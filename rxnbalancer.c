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
  @desc   Fetch reactants in an equation
  @author Brenton Bongcaron brenton3926@gmail.com
  @param  char** equation       --> array containing each "word" in chemical
                                    equation
          int argc              --> number of "words" in chemical equation
          int* numReactants     --> pointer to number of reactants in equation
*****************************************************************************/
char** getReactants(char** equation, int argc, int* numReactants);

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
  int numReactants = 0;
  char** reactants = getReactants(argv, argc, &numReactants);

  //printf("numReactants = %d\n", numReactants);
  printComponents(reactants, numReactants);
  // Free the malloc'ed reactants matrix
  freeMatrix(reactants, numReactants);
  return 0;
}

char** getReactants(char** equation, int argc, int* numReactants)
{
  int index = 1;
  int countReactants = 0;

  /* Count the number of reactants in the equation */
  while (strcmp(equation[index], "=") != 0 && index < (argc + 1))
  {
    if (strcmp(equation[index], "+") == 0)
    {
      index++;
      continue;
    }
    countReactants++;
    index++;
  }
  *numReactants = countReactants;
  /*
    Opted for dyanmic allocation of array instead of linked list because it is
     preferred to have instant access to all components in the equation at a
     given moment.
  */
  index = 1;
  int reactantIndex = 0;
  // the array of reactants
  char** reactants = malloc(sizeof(char*) * countReactants);

  /* Insert each reactant into char** reactants */
  while (strcmp(equation[index], "=") != 0 && index < (argc + 1))
  {
    if (strcmp(equation[index], "+") == 0)
    {
      index++;
      continue;
    }
    reactants[reactantIndex] = malloc(sizeof(char) * strlen(equation[index]));
    strcpy(reactants[reactantIndex], equation[index]);
    reactantIndex++;
    index++;
  }
  return reactants;
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
