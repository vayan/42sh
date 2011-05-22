/*
** xmalloc.c for xmalloc in /home/maurin_t//BSQ
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun Nov  7 20:06:34 2010 timothee maurin
** Last update Sun May 22 16:14:32 2011 Vaillant Yann
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include        <errno.h>
#include	"xmalloc.h"
#include	"shell.h"
#include	"prototype.h"

void		*xmalloc(int size)
{
  void		*tab;
  int		count;

  count = 0;
  if (!(tab = malloc(size)))
    {
      fprintf(stderr, "42sh : Malloc : %s\n", strerror(errno));
      exit(11);
    }
  while (count < size)
    {
      ((char*)tab)[count] = 0;
      count++;
    }
  return (tab);
}
