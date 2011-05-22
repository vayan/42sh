/*
** my_get_var.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun May 22 17:45:28 2011 maxime constantinian
** Last update Sun May 22 17:57:44 2011 maxime constantinian
*/

#include	"string.h"
#include	"shell.h"
#include	"prototype.h"

char		*my_get_var(char *to_find, t_list_var *variable)
{
  char		*ret = 0;

  while (variable)
    {
      if (variable->name)
	if (strcmp(to_find, variable->name) == 0)
	  {
	    if (variable->var)
	      ret = my_strcopynalloc(variable->var);
	    else
	      ret = xmalloc(1);
	  }
      variable = variable->next;
    }
  return (ret);
}
