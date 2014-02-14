#include <stdio.h>
#include <stdlib.h>

extern FILE *stderr, *stdin, *stdout;

int main(int argc, char ** argv)
{
  FILE * cfile;
  int i;
  int c;
  for(i = 1;i < argc;i++)
    { 
      cfile = fopen(argv[i],"r");
      if(!strcmp(argv[1],"--help"))
	{
	  printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\n   cat-lite README   Print the file README to standard output.\n   cat-lite f - g    Print f's contents, then standard input,\n                     then g's contents.\n   cat-lite          Copy standard input to standard output.\n");
	  return EXIT_SUCCESS;
	}
      if(cfile == NULL)
	{
	  if(!strcmp(argv[i],"-"))
	    {
	      printf("%s\n",stdin);
	    }
	  else
	    {
	      printf("cat cannot open %s\n",argv[i]);
	      return EXIT_FAILURE;
	    }
	}    
      else
	{  
	  while(1)
	    {
	      c = fgetc(cfile);
	      if(feof(cfile))
		{
		  break;
		  fclose(cfile);
		}
	      printf("%c", c);
	    }
	}
    }
  return EXIT_SUCCESS;
}
