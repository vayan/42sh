/*
** xread.c for xread in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 10:57:09 2011 timothee maurin
** Last update Thu May  5 17:25:24 2011 timothee maurin
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	"xmalloc.h"

int	xread(int fd, char *buf, int nb)
{
  int	i;

  i = 0;
  if ((i = read(fd, buf, nb)) == -1)
    fprintf(stderr, "read failed\n");
  buf[i] = 0;
  return (i);
}
