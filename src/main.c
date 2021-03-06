/*
** main.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Mar  8 11:45:43 2011 maxime constantinian
** Last update Sun Jun 12 16:27:53 2011 timothee maurin
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
#include	<string.h>
#include	<errno.h>
#include	"shell.h"
#include	"graph.h"
#include	"prototype.h"
#include	"termcap_include.h"

void		main_bis(t_shell *shell)
{
  shell->commande = xmalloc(sizeof(*(shell->commande)));
  shell->commande->buffer = get_next_line(0);
  parser(shell->commande->buffer, shell);
  exec_cmd(shell);
  free(shell->commande->buffer);
  free(shell->commande);
  exit(0);
}

void            nothing(int signal)
{
  static int	sauv;

  if (signal == SIGTTOU || signal == SIGTTIN)
    {
      if (tcgetpgrp(0) != sauv)
	if (tcsetpgrp(0, sauv) == -1)
	  fprintf(stderr, "42sh: tcsetpgrp failed: %s\n", strerror(errno));
    }
  else
    {
      xsignal(SIGQUIT, &funct_noexit);
      sauv = signal;
    }
}

int		main(int ac, char **av, char **envp)
{
  t_shell		*shell = xmalloc(sizeof(t_shell));
  struct termios	term2;

  nothing(getpgrp());
  ac = ac + (int)xsignal(SIGTTIN, nothing) * 0;
  av = av + copy_env(envp, shell) + (int)xsignal(SIGTTOU, nothing) * 0;
  add_hachtab_to_shell(shell);
  recup_shell(shell);
  parse_rc(shell);
  if (init_termios(&term2))
    main_bis(shell);
  desactivate_mode_raw(&term2);
  while (42)
    {
      xsignal(SIGINT, &funct_noexit);
      aff_prompt(0);
      cur_pos(0, 0, 0);
      mode_raw(&term2);
      get_next_comm(shell, &term2);
      desactivate_mode_raw(&term2);
      xsignal(SIGINT, &funct_exit);
      parser(shell->commande->buffer, shell);
      exec_cmd(shell);
    }
  return (0);
}
