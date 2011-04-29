/*
** xwrite.c for xwrite in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Sun Feb 27 13:26:35 2011 justin pugeat
** Last update Tue Mar 15 12:42:01 2011 justin pugeat
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	xwrite(int fd, char *str, int len)
{
  if (write(fd, str, len) == -1)
    exit(xwrite(2, "Error on write\n", 15));
  return (0);
}
