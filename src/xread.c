/*
** xread.c for xread in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 10:57:09 2011 timothee maurin
** Last update Sat Apr 30 18:52:41 2011 timothee maurin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "xmalloc.h"

char	*xread(int fd, char *buf, int nb)
{
  int	i;

  i = 0;
  buf = xmalloc(256 * sizeof(*buf));
  read(fd, buf, nb);
  while (buf[i] != '\0')
    {
      if (buf[i] == '\n')
	buf[i] = '\0';
      i++;
    }
  return (buf);
}
