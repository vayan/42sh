/*
** xopen.c for  in /home/vailla_y//Projet/42shtest/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu May  5 13:48:43 2011 yann vaillant
** Last update Wed May 18 17:44:01 2011 timothee maurin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	xopen(char *pathname, int flags)
{
  int	fd = 0;

  if ((fd = open(pathname, flags)) == -1)
    {
      printf("Open failed\n");
      exit (42);
    }
  return (fd);
}
