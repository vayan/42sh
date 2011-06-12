/*
** exec_fork_group.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun Jun 12 17:41:49 2011 maxime constantinian
** Last update Sun Jun 12 18:02:15 2011 maxime constantinian
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

int		set_group(int returnfork, int sauv)
{
  if (sauv == 0)
    {
      if (setpgid(returnfork, returnfork) == -1)
	fprintf(stderr, "42sh: setpgid failed: %s\n", strerror(errno));
      if (tcsetpgrp(0, getpgid(returnfork)) == -1)
	fprintf(stderr, "42sh: tcsetpgrp failed: %s\n", strerror(errno));
      sauv = returnfork;
    }
  else
    {
      if (setpgid(returnfork, sauv) == -1)
	fprintf(stderr, "42sh: setpgid failed: %s\n", strerror(errno));
      if (tcsetpgrp(0, getpgid(returnfork)) == -1)
	fprintf(stderr, "42sh: tcsetpgrp failed: %s\n", strerror(errno));
    }
  return (sauv);
}

int		invalid_cmd_why(t_commande *cmd, int *d)
{
  if ((cmd->type == OP_SRR || cmd->type == OP_DRR
       || cmd->type == OP_SRL || cmd->type == OP_DRL) && *d == 0)
    {
      if (check_if_have_cmd(cmd) == 0)
        return (fprintf(stderr, "Invalid null command.\n") * 0 - 1);
      else
        *d = 1;
    }
  else if ((cmd->type == OP_SRR || cmd->type == OP_DRR
            || cmd->type == OP_SRL || cmd->type == OP_DRL) && *d == 1)
    *d = 0;
  return (0);
}
