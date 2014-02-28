#include <stdio.h>
#include <stdlib.h>

#include "answer06.h"

void partprint(int pos, int * part)
{
  printf("= ");
  int i;
  for(i = 0; i < pos; i++)
    {
      if(i)
	{
	  printf(" + ");
	}
      printf("%d",part[i]);
    }
  printf("\n");
}
void helppartALL(int val, int * part, int pos)
{
  if(val == 0)
    {
      partprint(pos,part);
    }
  int i;
  for(i = 1; i <= val; i++)
    {
      part[pos] = i;
      helppartALL(val - i, part, pos + 1);
    }
}


void partitionALL(int value)
{
  int * part = malloc(sizeof(int) * value);
  helppartALL(value,part,0);
  free(part);
}

int main(int argc, char ** argv)
{
  if(argc != 2)
    {
      printf("DANGER WILL ROBINSON, DANGER!!!\n");
      return EXIT_FAILURE;
    }
  partitionALL(atoi(argv[1]));
  return(0);
}
