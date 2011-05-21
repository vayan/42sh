/*
** xwrite.c for xwrite in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Sun Feb 27 13:26:35 2011 justin pugeat
** Last update Fri May 20 19:47:00 2011 timothee maurin
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "prototype.h"

void	my_putstr_del(char *buf)
{
  int	i;

  i = 0;
  while (buf[i] != '\0')
    {
      if (nbr_column() && ((cur_pos(buf, i, 1)) % nbr_column()) == 0 && i != 0)
	xwrite(0, "\n", 1);
      xwrite(0, &(buf[i]), 1);
      i++;
    }
  if (nbr_column() && ((cur_pos(buf, i, 1)) % nbr_column()) == 0 && i != 0)
    xwrite(0, "\n", 1);
}

int	xwrite(int fd, char *str, int len)
{
  if (write(fd, str, len) == -1)
    {
      fprintf(stderr, "Error on write\n");
      return (1);
    }
  return (0);
}

int	my_putstr_buf(char *str, int i1, int pos, char *buf)
{
  int	i;

  i1 = i1;
  i = 0;
  while (str[i] != '\0')
    {
      xwrite(0, &(str[i]), 1);
      if (nbr_column() && ((cur_pos(buf, pos + i, 1)) % nbr_column()) == 0)
	write(0, "\n", 1);
      i++;
    }
  return (0);
}
