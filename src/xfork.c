/*
** xfork.c for xfork in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:27:42 2011 timothee maurin
** Last update Thu May  5 16:13:55 2011 timothee maurin
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int     xfork()
{
  int   pid;

  pid = fork();
  if (pid == -1)
    fprintf(stderr, "42sh: Fork failed\n");
  return (pid);
}
