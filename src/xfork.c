/*
** xfork.c for xfork in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:27:42 2011 timothee maurin
** Last update Sat Mar  5 22:57:49 2011 timothee maurin
*/

#include <stdlib.h>
#include <unistd.h>

int	xfork()
{
  int	pid;

  pid = fork();
  if (pid == -1)
    {
      write(2, "error", 5);
      exit(42);
    }
  return (pid);
}
