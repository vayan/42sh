/*
** exit_func.c for exit_func in /home/schoen_a//42sh/42sh/src
** 
** Made by arnaud schoenher
** Login   <schoen_a@epitech.net>
** 
** Started on  Wed May  4 15:55:26 2011 arnaud schoenher
** Last update Sun May 22 19:45:11 2011 maxime constantinian
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
  shell->commande->buffer = 0;
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

void			free_commande(t_commande_root *list)
{
  t_commande_root	*tmp;

  if (list)
    {
      while (list->before_histo)
	list = list->before_histo;
      while (list)
	{
	  tmp = list->next_histo;
	  if (list->buffer)
	    free(list->buffer);
	  free(list);
	  list = tmp;
	}
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
      free_commande(tmp);
    }
  free(shell);
}

int		exit_func(char **av, char **env)
{
  char		*last_exit;
  int		end_av;
  int		ret;
  t_shell	*shell = recup_shell(0);

  end_av = go_end_env(av);
  func_old_pwd(2);
  aff_prompt(1);
  if (end_av == 1)
    {
      free_graph_parseur(shell->commande->cmd);
      last_exit = my_get_var("?", shell->variable);
      free_shell(shell);
      if (last_exit != 0)
	exit(my_getnbr(last_exit) + xfree(last_exit));
      exit(0);
    }
  if (end_av > 1)
    {
      ret = my_getnbr(av[1]);
      free_graph_parseur(shell->commande->cmd);
      free_shell(shell);
      exit(ret);
    }
  return (0);
}
