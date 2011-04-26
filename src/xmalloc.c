/*
** xmalloc.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr  6 12:40:42 2011 maxime constantinian
** Last update Wed Apr  6 12:48:36 2011 maxime constantinian
*/

#include	<stdio.h>
#include	<stdlib.h>

void		*xmalloc(int size)
{
  void		*ptr;
  int		i;

  i = 0;
  ptr = malloc(size);
  if (ptr == NULL)
    exit(fprintf(stderr, "42sh: Malloc failed\n"));
  while (i < size)
    ((char *)ptr)[i++] = 0;
  return (ptr);
}
