/*
** func_cd.c for 42sh in /home/maurin_t//mesfonction
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat Apr 30 18:08:51 2011 timothee maurin
** Last update Sat May 21 17:23:24 2011 timothee maurin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

int		funct_cd_move(char **av, char **env,
			      int *option, int *tab)
{
  char		*home;

  home = my_get_env("HOME", env);
  if (av[1][0] == '-' && av[1][1] == '\0')
    {
      free(av[1]);
      av[1] = my_get_env("OLDPWD", env);
    }
  if (av[1][0] == '~' && home != 0)
    av[1] = concat(home, av[1]);
  if (!(access(av[1], F_OK)))
    {
      change_env_last(env, tab);
      change_dir(av, env, tab);
    }
  else
    {
      fprintf(stderr, "%s: No such file or directory.\n", av[1]);
      return (1);
    }
  return (0);
}

int		move_home(char **av, char **env, int *option, int *tab)
{
  char		*home;
  char		*tmp;
  char		*pwd;

  home = my_get_env("HOME", env);
  if (home != 0)
    {
      tmp = xmalloc(2 * sizeof(*tmp));
      tmp[0] = '/';
      pwd = xmalloc(2 * sizeof(*pwd));
      pwd[0] = '/';
      if (!(access(home, F_OK)))
	{
	  change_env_last(env, tab);
	  chdir(home);
	  change_env(env, tab);
	}
      else
	return (write_error("%s: No such file or directory.\n", home));
      return (0);
    }
  else
    return (write_error(": No such file or directory.\n", 0));
}

int		rempl_option(char **av, int *option)
{
  int		i;
  int		n;

  i = 1;
  while (av[i] && av[i][0] == '-')
    {
      n = 1;
      while (av[1][n] != '\0')
	{
	  if (av[i][n] == 'p')
	    option[0] = 1;
	  if (av[i][n] == 'l')
	    option[1] = 1;
	  n++;
	}
      i++;
    }
  return (0);
}

int		exec_cd(char **av, char **env, int *tab)
{
  int		*option;
  char		*pwd;
  char		*tmp;

  option = xmalloc(2 * sizeof(*option));
  pwd = xmalloc(2 * sizeof(*pwd));
  pwd[0] = '/';
  tmp = xmalloc(2 * sizeof(*tmp));
  tmp[0] = '/';
  if (count_param(av) > 2)
    return (fprintf(stderr, "42sh: cd: Too many arguments.\n"));
  if (rempl_option(av, option) == -1)
    {
      fprintf(stderr, "Usage: cd [-pl][<dir>].\n");
      return (1);
    }
  else if (count_param(av) == 1)
    return (move_home(av, env, option, tab));
  else
    return (funct_cd_move(av, env, option, tab));
  return (1);
}
