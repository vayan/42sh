/*
** xclose.c for  in /home/vailla_y/Projet/42shtest/src
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Sun May 22 15:41:39 2011 Vaillant Yann
** Last update Sun May 22 16:06:25 2011 Vaillant Yann
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int	xclose(int fd)
{
  if (close(fd) == -1)
    {
      fprintf(stderr, "42sh: Close : %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
