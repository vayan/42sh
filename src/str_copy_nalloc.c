/*
** str_copy_nalloc.c for  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 26 17:25:15 2011 yann vaillant
** Last update Sat Jun 11 19:28:43 2011 maxime constantinian
*/

#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"
#include	"graph.h"
#include	"xmalloc.h"

char	*my_strcopynalloc_gen(char *src, int len)
{
  char	*retour;
  int	x = 0;

  if (src == 0)
    return (0);
  retour = xmalloc((len + 1) * sizeof(*retour));
  while (x < len && src[x])
    {
      retour[x] = src[x];
      x++;
    }
  retour[x] = '\0';
  return (retour);
}

char	*my_strcopynalloc(char *src)
{
  char	*retour;
  int	x = 0;

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
