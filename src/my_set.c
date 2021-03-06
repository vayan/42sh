/*
** my_set.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 21 15:34:56 2011 timothee maurin
** Last update Sun Jun 12 16:30:08 2011 timothee maurin
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"shell.h"
#include	"prototype.h"

int		aff_var(t_list_var *list_var, int *tab)
{
  while (list_var)
    {
      if (list_var->name)
	{
	  xwrite(tab[1], list_var->name, strlen(list_var->name));
	  xwrite(tab[1], "=", 1);
	  if (list_var->var)
	    xwrite(tab[1], list_var->var, strlen(list_var->var));
	  xwrite(tab[1], "\n", 1);
	}
      list_var = list_var->next;
    }
  return (0);
}

t_list_var	*add_to_set_list(char **tmp, t_list_var *list_var)
{
  t_list_var	*end;

  end = list_var;
  while (end->next != 0)
    end = end->next;
  if (check_if_exist_in_list(tmp[1], list_var) == 0)
    add_var_to_list(tmp, end);
  else
    update_var_in_list(tmp, list_var);
  return (list_var);
}

int             my_unset(char **av)
{
  int           i;
  t_shell       *shell = recup_shell(0);

  if (!(shell->variable))
    shell->variable = xmalloc(sizeof(t_list_var));
  i = 0;
  if (av[1] == 0)
    {
      fprintf(stderr, "unset: Too few arguments.\n");
      return (1);
    }
  while (av[++i])
    remove_var_in_list(av[i], &(shell->variable), shell->variable);
  return (0);
}

int		free_tmp_set(char **tmp, int test)
{
  if (tmp)
    {
      if (tmp[1])
	{
	  free(tmp[1]);
	  tmp[1] = 0;
	}
      if (tmp[2])
	{
	  free(tmp[2]);
	  tmp[2] = 0;
	}
      if (test == 0)
	free(tmp);
    }
  return (1);
}

int		my_set(char **av, int *tab)
{
  int		tmp_nb;
  char		**tmp = xmalloc(4 * sizeof(*tmp));
  t_shell	*shell = recup_shell(0);
  int		i = 0;

  if (!(shell->variable))
    shell->variable = xmalloc(sizeof(t_list_var));
  if (av[1] == 0 && free_tmp_set(tmp, 0))
    return (aff_var(shell->variable, tab));
  while (av[++i])
    {
      tmp[2] = 0;
      if (check_equal(av[i]) == 1)
	tmp[1] = strdup(av[i]);
      else if ((tmp_nb = strlen_equal(av[i])))
	{
	  tmp[1] =  strndup(av[i], tmp_nb);
	  tmp[2] = strdup(&(av[i][tmp_nb + 1]));
	}
      add_to_set_list(tmp, shell->variable);
      free_tmp_set(tmp, 1);
    }
  free_tmp_set(tmp, 0);
  return (0);
}
