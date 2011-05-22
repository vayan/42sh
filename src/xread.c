/*
** xread.c for xread in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 10:57:09 2011 timothee maurin
** Last update Sun May 22 16:16:50 2011 Vaillant Yann
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	<string.h>
#include	<errno.h>
#include	"xmalloc.h"

int	xread(int fd, char *buf, int nb)
{
  int	i;

  i = 0;
  if ((i = read(fd, buf, nb)) == -1)
    fprintf(stderr, "42sh : Read : %s\n", strerror(errno));
  buf[i] = 0;
  return (i);
}
