/*
** str_copy_nalloc.c for  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 26 17:25:15 2011 yann vaillant
** Last update Tue Apr 26 18:24:26 2011 yann vaillant
*/

#include	<stdlib.h>
#include        "graph.h"
#include        "shell.h"
#include        "xmalloc.h"
#include        "header.h"

char    *my_strcopynalloc(char *src)
{
  char  *retour;
  int   x = 0;
  
  if (src == NULL)
    return (NULL);
  retour = xmalloc((strlen(src) + 1) * sizeof(*retour));
  while (src[x])
    {
      retour[x] = src[x];
      x++;
    }
  retour[x] = '\0';
  return (retour);
}
