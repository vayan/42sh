/*
** exit_func.c for exit_func in /home/schoen_a//42sh/42sh/src
** 
** Made by arnaud schoenher
** Login   <schoen_a@epitech.net>
** 
** Started on  Wed May  4 15:55:26 2011 arnaud schoenher
** Last update Sun May 22 17:38:20 2011 timothee maurin
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

void		free_var(t_list_var *list)
{
  if (list)
    {
      if (list->next != 0)
        free_var(list->next);
      if (list->name)
	free(list->name);
      if (list->var)
	free(list->var);
      free(list);
    }
}

void		free_commande(t_commande_root *list)
{
  if (list)
    {
      if (list->before_histo != 0)
        free_commande(list->before_histo);
      if (list->buffer)
	free(list->buffer);
      free(list);
    }
}

void			free_shell(t_shell *shell)
{
  t_commande_root	*tmp;

  if (shell->tab_hach)
    free_graph(shell->tab_hach);
  if (shell->env)
    free_tab(shell->env);
  if (shell->alias)
    free_var(shell->alias);
  if (shell->variable)
    free_var(shell->variable);
  if (shell->commande)
    {
      tmp = shell->commande;
      while (tmp->next_histo != 0)
	tmp = tmp->next_histo;
      free_commande(tmp);
    }
  free(shell);
}

int		exit_func(char **av, char **env)
{
  char		*last_exit;
  int		end_av;

  end_av = go_end_env(av);
  func_old_pwd(2);
  aff_prompt(1);
  if (end_av == 1)
    {
      last_exit = my_get_env("?", env);
      if (last_exit != 0)
	exit(my_getnbr(last_exit));
      free_shell(recup_shell(0));
      exit(0);
    }
  if (end_av > 1)
    {
      free_shell(recup_shell(0));
      exit(my_getnbr(av[1]));
    }
  return (0);
}
