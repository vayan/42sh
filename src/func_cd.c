/*
** func_cd.c for 42sh in /home/maurin_t//mesfonction
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat Apr 30 18:08:51 2011 timothee maurin
** Last update Mon May 23 12:01:36 2011 timothee maurin
*/

#include	<string.h>
#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

int		funct_cd_move(char **av, char **env,
			      int *tab)
{
  char		*home = my_get_env("HOME", env);

  if (av[1][0] == '-' && av[1][1] == '\0')
    {
      free(av[1]);
      av[1] = func_old_pwd(0);
    }
  if (av[1] && av[1][0] == '~' && home != 0)
    {
      if (av[1][1] == 0)
	av[1] = concat(home, &(av[1][1]));
      else if (av[1][1] == '/')
	av[1] = concat(home, &(av[1][2]));
    }
  free(home);
  if (av[1] && !(access(av[1], F_OK)))
    return (change_dir(av, env, tab));
  else
    return (fprintf(stderr, "42sh: Cd : %s\n", strerror(errno)));
  return (0);
}

int		move_home(char **env, int *tab)
{
  char		*home;

  home = my_get_env("HOME", env);
  if (home != 0)
    {
      if (!(access(home, F_OK)))
	{
	  func_old_pwd(1);
	  chdir(home);
	  change_env(env, tab);
	}
      else
	return (fprintf(stderr, "42sh: Cd : %s\n", strerror(errno)));
      return (0);
    }
  else
    return (fprintf(stderr, "42sh: Cd : %s\n", strerror(errno)));
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
	  else if (av[i][n] == 'l')
	    option[1] = 1;
	  else
	    return (-1);
	  n++;
	}
      i++;
    }
  return (0);
}

int		exec_cd(char **av, char **env, int *tab)
{
  if (count_param(av) > 2)
    return (fprintf(stderr, "42sh: cd: Too many arguments.\n"));
  if (count_param(av) == 1)
    return (move_home(env, tab));
  else
    return (funct_cd_move(av, env, tab));
  return (1);
}
