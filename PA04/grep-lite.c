#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gfunc(int argc, const char ** argv,int find, int inv, int line)
{
  FILE * cfile;
  int i;
  char * str;
  int x = 2000;
  int n = 1;
  for(i = 0;i < argc; i++)
    {
      if(strcmp(argv[i],"-v") && strcmp(argv[i],"-n"))
	{
	  cfile = fopen(argv[i],"r");
	  if(cfile == NULL)
	    {
	      printf("cannot open %s\n",argv[i])
		return(2);
	    }
	  else
	    {
	      while(1)
		{
		  if(feof(cfile))
		    {
		      break;
		      fclose(cfile);
		    }
		  char * fgets(char * str, int x, FILE * cfile);
		  puts(str);
		  n++
		    if(!(strstr(str,find)==NULL)||(inv && strstr(str,find) == NULL))
		    {
		      if(line == 1)
			{
			  printf("%d ", n);
			}
		      printf("%s",str);
		      if(feof(cfile))
			{
			  break;
			  fclose(cfile);
			  return(0)
		    }
		  
		}
	    }
	}
    }
      return(1)
}
	      
int nfunc(int argc, const char ** argv,int find, int inv)
{
  int i;
  int line = 0;
  for(i = 1; i < argc;i++)
    {
      if(!strcmp(argv[i],"-n"))
	{
	  line = 1;
	  check = gfunc(int argc, const char **argv, int inv, int line);
	  return check;
	}
    }
  check = gfunc(int argc, const char ** argv, int inv, int line);
  return check;
}
	  
	  
	  

    
  
int main(int argc, char ** argv)
{
  int i;
  int inv = 0;
  int check;
  for(i = 1; i < argc;i++)
  {
    if(!strcmp(argv[1],"--help"))
	{
	  printf("//Usage: grep-lite [OPTION]... PATTERN\nSearch for PATTERN in standard input. PATTERN is a\nstring. grep-lite will search standard input line by line, and (by default) print out those lines which\ncontain pattern as a substring.\n\n  -v, --invert-match     print non-matching lines\n  -n, --line-number      print line number with output\n  -q, --quiet            suppress all output\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, then the exit status is 2.\n");
	  return EXIT_SUCCESS;
	}
      if(!strcmp(argv[i],"-q"))
	{
	  return EXIT_SUCCESS;
	}
  }
  for(i = 1; i < argc; i++)
    {
      if(!strcmp(argv[i],"-v"))
	{
	  int inv = 1;
	  check = nfunc(int argc, const char ** argv,int find, int inv);
	  return check;
	}
    }
  int line = 0;
  check = gfunc(int argc, const char ** argv,int find, int inv, int line);
  return check;
}
