/*
** xmalloc.c for xmalloc in /home/maurin_t//BSQ
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun Nov  7 20:06:34 2010 timothee maurin
** Last update Sat Apr 30 18:56:26 2011 timothee maurin
*/
#include <stdlib.h>
#include <unistd.h>
#include "xmalloc.h"

void		*xmalloc(int size)
{
  void		*tab;
  int		count;

  count = 0;
  if (!(tab = malloc(size)))
    {
      write(1, "allocation failed", strlen("allocation failed"));
      exit(42);
    }
  while (count < size)
    {
      ((char*)tab)[count] = 0;
      count++;
    }
  return (tab);
}
