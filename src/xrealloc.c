/*
** xrealloc.c for 42sh in /home/consta_m/soutenance/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Mon Jun  6 14:09:09 2011 maxime constantinian
** Last update Mon Jun  6 14:14:58 2011 maxime constantinian
*/

#include	<string.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>

void		*xrealloc(void *ptr, unsigned int size)
{
  void		*ret = 0;

  if (!(ret = realloc(ptr, size)))
    exit(fprintf(stderr, "42sh : Malloc : %s\n", strerror(errno)));
  return (ret);
}
