/*
** my_set.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 21 15:34:56 2011 timothee maurin
** Last update Sat May 21 18:45:59 2011 timothee maurin
*/

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

int		my_set(char **av, char **env, int *tab)
{
  int		tmp_nb;
  char		**tmp = xmalloc(3 * sizeof(*tmp));
  t_shell	*shell = recup_shell(0);
  int		i = 0;

  if (!(shell->variable))
    shell->variable = xmalloc(sizeof(t_list_var));
  if (av[1] == 0)
    return (aff_var(shell->variable, tab));
  while (av[++i])
    {
      tmp[1] = '\0';
      if (check_equal(av[i]) == 1)
	{
	  tmp[0] = strdup(av[i]);
	  write(1, "a", 1);
	}
      else if ((tmp_nb = strlen_equal(av[i])))
	{
	  tmp[0] =  strndup(av[i], tmp_nb);
	  tmp[1] = strdup(&(av[i][tmp_nb + 1]));
	  av[i][tmp_nb] = '\0';
	}
      if (check_if_exist_in_list(tmp[0], shell->variable))
	add_var_to_list(tmp, shell->variable);
      else
	update_var_in_list(tmp, shell->variable);
    }
  return (0);
}
