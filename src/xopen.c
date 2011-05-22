/*
** xopen.c for  in /home/vailla_y//Projet/42shtest/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu May  5 13:48:43 2011 yann vaillant
** Last update Sun May 22 16:08:49 2011 Vaillant Yann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int	xopen(char *pathname, int flags)
{
  int	fd = 0;
  
  if ((fd = open(pathname, flags)) == -1)
    {
      fprintf(stderr, "42sh : Open : %s\n", strerror(errno));
      return (-1);
    }
  return (fd);
}
