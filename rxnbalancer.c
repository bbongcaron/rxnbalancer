#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[argc+1])
{
  int index = 1;
  int numReactants = 0;

  while (strcmp(argv[index], "=") != 0 && index < (argc + 1))
  {
    if (strcmp(argv[index], "+") == 0)
    {
      index++;
      continue;
    }
    printf("%s\n", argv[index]);
    numReactants++;
    index++;
  }

  printf("numReactants = %d\n", numReactants);

  return 0;
}
