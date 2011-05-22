/*
** xfork.c for xfork in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:27:42 2011 timothee maurin
** Last update Sun May 22 16:33:17 2011 Vaillant Yann
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int     xfork()
{
  int   pid;

  pid = fork();
  if (pid == -1)
    fprintf(stderr, "42sh: Fork : %s\n", strerror(errno));
  return (pid);
}
