/*
** xwrite.c for xwrite in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Sun Feb 27 13:26:35 2011 justin pugeat
** Last update Thu May  5 15:55:45 2011 timothee maurin
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	xwrite(int fd, char *str, int len)
{
  if (write(fd, str, len) == -1)
    {
      xwrite(2, "Error on write\n", 15);
      return (1);
    }
  return (0);
}

int	my_putstr_buf(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      xwrite(0, &(str[i]), 1);
      i++;
    }
  return (0);
}
