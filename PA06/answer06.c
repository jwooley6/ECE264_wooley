#include <stdio.h>
#include <stdlib.h>

#include "answer06.h"

void partprint(int numarg, int * part)
{
  printf("= ");
  int i;
  for(i = 0; i < numarg; i++)
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

void helppartInc(int val, int * part, int pos)
{
  if(val == 0)
    {
      int x;
      int inc = 0;
      for(x = 0; x < pos-1; x++)
	{
	  //printf("part = %d pos = %d\n",part[x],pos);
	  if(part[x] < part[x+1])
	    {
	      inc++;
	      //printf("%d",pos);
	      if(inc == pos - 1)
		{
		  partprint(pos,part);
		}
	    }
	}
    }
  int i;
  for(i = 1; i <= val; i++)
    {
      part[pos] = i;
      //printf("part %d pos %d", part[pos],pos);
      helppartInc(val - i, part, pos + 1);
    }
  //printf("val %d pos %d",val,pos)
  if(pos == 0)
    {
      printf("= %d\n",val);
    }
}

void helppartDec(int val,int *part,int pos)
{
if(val == 0)
    {
      int x;
      int dec = 0;
      for(x = 0; x < pos-1; x++)
	{
	  if(part[x] > part[x+1])
	    {
	      dec++;
	      if(dec == pos - 1)
		{
		  partprint(pos,part);
		}
	    }
	}
    }
 int i;
 for(i = 1; i <= val; i++)
   {
     part[pos] = i;
     helppartDec(val - i, part, pos + 1);
   }
 if(pos == 0)
   {
     printf("= %d\n",val);
     
   }
}
void helppartOdd(int val, int * part, int pos)
{
  if(val == 0)
    {
      int j = 0;
      int num = 0;
      //printf("J SHOULD BE FUCKING ZERO j = %d\n",j);
      //printf("outest part %d\n",part[0]);
      //partprint(pos,part);
      for(j = 0; j < pos; j++)
	{
	  //printf("J SHOULD BE FUCKING ZERO j = %d\n",j);
	  if((part[j] % 2) == 1)
	    {
	      num++;
	      //printf("inner num %d pos %d\n",num,pos);
	      //partprint(pos,part);
	      if(num == pos)
		{
		  partprint(pos,part);
		}
	    }
	}
    }
  int i;
  for(i = 1; i <= val; i++)
    {
      part[pos] = i;
      helppartOdd(val - i, part, pos + 1);
    }
}

void partitionALL(int value)
{
  int * part = malloc(sizeof(int) * value);
  printf("All\n\n");
  helppartALL(value,part,0);
  free(part);
}

void partitionIncreasing(int value)
{
  int *part = malloc(sizeof(int) * value);
  printf("\nIncreasing\n\n");
  helppartInc(value,part,0);
  free(part);
}

void partitionDecreasing(int value)
{
  int * part = malloc(sizeof(int) * value);
  printf("\nDecreasing\n\n");
  helppartDec(value,part,0);
  free(part);
}
void partitionOdd(int value)
{
  int * part = malloc(sizeof(int) * value);
  printf("\nOdd\n\n");
  helppartOdd(value,part,0);
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
  partitionIncreasing(atoi(argv[1]));
  partitionDecreasing(atoi(argv[1]));
  partitionOdd(atoi(argv[1]));
  return(0);
}
