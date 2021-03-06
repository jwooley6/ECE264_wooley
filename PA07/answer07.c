#include <stdio.h>
#include <stdlib.h>

#include "answer07.h"

List * List_createNode(const char * str)
{
  List  * node  = malloc(sizeof(List));
  node -> str = strdup(str);
  node -> next = NULL;

  return node;
}

void List_destroy(List * list)
{
  if(list == NULL)
    {
      return;
    }
  List_destroy(list -> next);
  free(list->str);
  free(list);
}

int List_length(List * list)
{
  if(list == NULL)
    {
      return(0);
    }
  return(1+List_length(list->next));
}

List * List_merge(List * l, List * r,int(*compar)(const char *, const char *))
{
  if((l==NULL)&&(r==NULL))
    {
      return NULL;
    }
  else if(l==NULL)
    {
      return(r);
    }
  else if(r==NULL)
    {
      return(l);
    }
  while(l != NULL && r != NULL)
    {
      List * head;
      List * tail;
      int cmp = compar(l->str, r->str);
      if(cmp <= 0)
	{
	  if(tail == NULL)
	    {
	      head = l;
	      tail = r;
	    }
	  else
	    {
	      tail -> next = l;
	      tail = l;
	      l = l -> next;
	      tail -> next = NULL;
	      tail -> next = (l = NULL ? r : l);
	      return(head);
}

struct List List_sort(List * list, int(*compar)(const char *, const char *))
{
  int length = List_length(list);
  if(length <= 1)
    {
      return(list);
    }
  half = length / 2;
  List *l = list;
  List * l_tail = list;
  while(half > 0)
    {
      l_tail = l_tail -> next;
    }
  List * r = l_tail -> next;
  l_tail -> next = NULL;
  l = List_sort(l,compar);
  r = List_sort(r,compar);
  return(l,r,compar);
}

int main(int argc, char * argv)
{
  return(0);
}
