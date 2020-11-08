#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    //printf("%s\n", argv[index]);
    numReactants++;
    index++;
  }
  //printf("numReactants = %d\n", numReactants);

  /*
    Opted for dyanmic allocation of array instead of linked list because it is
     preferred to have instant access to all components in the equation at a
     given moment.
  */

  return 0;
}
