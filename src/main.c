/*
** main.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Mar  8 11:45:43 2011 maxime constantinian
** Last update Tue Apr 26 18:52:04 2011 maxime constantinian
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<sys/ioctl.h>
#include	<sys/types.h>
#include	<termcap.h>
#include	<termios.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	<signal.h>
#include	"shell.h"
#include	"graph.h"
#include	"xmalloc.h"

int		main(int ac, char **av, char **envp)
{
  t_shell *shell = malloc(sizeof(t_shell));

  if (ac)
    if (av)
      {
      }
  copy_env(envp, shell);
  printf("test \n%s\n", shell->env[5]);
  return (0);
}
