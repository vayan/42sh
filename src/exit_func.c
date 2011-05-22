/*
** exit_func.c for exit_func in /home/schoen_a//42sh/42sh/src
** 
** Made by arnaud schoenher
** Login   <schoen_a@epitech.net>
** 
** Started on  Wed May  4 15:55:26 2011 arnaud schoenher
** Last update Sun May 22 14:33:01 2011 timothee maurin
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"
#include	"shell.h"
#include	"prototype.h"

void		exit_buf(char *buf, char *cha)
{
  char		*av[] = {"exit", "0", 0};
  t_shell	*shell;

  buf = buf;
  shell = recup_shell(0);
  free_buf(shell->commande->buffer, 1);
  free(shell->commande->buffer);
  free(cha);
  xwrite(0, "\n", 1);
  exit_func(av, shell->env);
}

int		exit_func(char **av, char **env)
{
  char		*last_exit;
  int		end_av;
  t_shell	*shell;

  end_av = go_end_env(av);
  shell = recup_shell(0);
  if (shell->tab_hach)
    free_graph(shell->tab_hach);
  if (end_av == 1)
    {
      last_exit = my_get_env("?", env);
      if (last_exit != 0)
	exit(my_getnbr(last_exit));
      exit(0);
    }
  func_old_pwd(2);
  aff_prompt(1);
  if (end_av > 1)
    exit(my_getnbr(av[1]));
  return (0);
}
