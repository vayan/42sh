/*
** main.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Mar  8 11:45:43 2011 maxime constantinian
** Last update Thu May  5 12:54:20 2011 timothee maurin
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
#include	"prototype.h"
#include	"termcap_include.h"

int		main(int ac, char **av, char **envp)
{
  t_shell *shell = xmalloc(sizeof(t_shell));
  struct termios	term2;

  ac = ac;
  av = av;
  mode_raw(&term2);
  copy_env(envp, shell);
  add_hachtab_to_shell(shell);
  //  while (42)
    {
      get_next_comm(shell, &term2);
      parser(shell->commande->buffer, shell);
      exec_cmd(shell);
    }
  return (0);
}
