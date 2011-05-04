/*
** xmalloc.c for xmalloc in /home/maurin_t//BSQ
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun Nov  7 20:06:34 2010 timothee maurin
** Last update Wed May  4 17:17:21 2011 timothee maurin
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "xmalloc.h"

void		*xmalloc(int size)
{
  void		*tab;
  int		count;

  count = 0;
  if (!(tab = malloc(size)))
    {
      xwrite(2, "allocation failed", strlen("allocation failed"));
      exit(42);
    }
  while (count < size)
    {
      ((char*)tab)[count] = 0;
      count++;
    }
  return (tab);
}
