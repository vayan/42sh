/*
** my_set.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 21 15:34:56 2011 timothee maurin
** Last update Wed Jun  8 19:04:01 2011 timothee maurin
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"shell.h"
#include	"prototype.h"

int             my_unset_alias(char **av)
{
  int           i;
  t_shell       *shell = recup_shell(0);

  if (!(shell->variable))
    shell->alias = xmalloc(sizeof(t_list_var));
  i = 0;
  if (av[1] == 0)
    {
      fprintf(stderr, "unset: Too few arguments.");
      return (1);
    }
  while (av[++i])
    remove_var_in_list(av[i], shell->alias);
  return (0);
}

int		free_tmp_alias(char **tmp, int test)
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

int		my_set_alias(char **av, int *tab)
{
  int		tmp_nb;
  char		**tmp = xmalloc(4 * sizeof(*tmp));
  t_shell	*shell = recup_shell(0);
  int		i = 0;

  if (!(shell->alias))
    shell->alias = xmalloc(sizeof(t_list_var));
  if (av[1] == 0 && free_tmp_alias(tmp, 0))
    return (aff_var(shell->alias, tab));
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
      add_to_set_list(tmp, shell->alias);
      free_tmp_alias(tmp, 1);
    }
  free_tmp_alias(tmp, 0);
  return (0);
}
