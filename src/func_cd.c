/*
** func_cd.c for 42sh in /home/maurin_t//mesfonction
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat Apr 30 18:08:51 2011 timothee maurin
** Last update Tue May  3 17:11:33 2011 timothee maurin
*/

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
  exec_cd(&(av[1]), env);
}

int	count_param(char **av)
{
  int	i;

  i  = 0;
  while (av[i] != 0 && (av[i][0] != '-' || av[i][1] == '\0'))
    i++;
  return (i);
}

int		funct_cd_move(char **av, char **env, int *option, char **last_cd)
{
  char		*home;
  char		*tmp;
  char		*pwd;

  home = my_get_env("HOME", env);
  if (av[1][0] == '~' && home != 0)
    av[1] = concat(home, av[1]);
  tmp = xmalloc(2 * sizeof(*tmp));
  tmp[0] = '/';
  pwd = xmalloc(2 * sizeof(*pwd));
  pwd[0] = '/';
  if (!(access(av[1], F_OK)))
    {
      if (*last_cd != 0)
	free(*last_cd);
      *last_cd = my_pwd(tmp);
      chdir(av[1]);
      pwd = my_pwd(pwd);
      //      my_setenv();
      free(pwd);
    }
  else
    {
      fprintf(stderr, "%s: No such file or directory.\n", av[1]);
      return (1);
    }
  return (0);
}

int		move_home(char **av, char **env, int *option, char **last_cd)
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
	  if (*last_cd != 0)
	    free(*last_cd);
	  *last_cd = my_pwd(tmp);
	  chdir(home);
	  printf("%s", home);
	}
      else
	{
	  fprintf(stderr, "%s: No such file or directory.\n", home);
	  return (1);
	}
      return (0);
    }
  else
    {
      return (1);
      fprintf(stderr, ": No such file or directory.\n");
    }
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

int		exec_cd(char **av, char **env)
{
  int		*option;
  static char	*last_cd;
  char		*pwd;
  char		*tmp;

  option = xmalloc(2 * sizeof(*option));
  pwd = xmalloc(2 * sizeof(*pwd));
  pwd[0] = '/';
  tmp = xmalloc(2 * sizeof(*tmp));
  tmp[0] = '/';
  if (count_param(av) > 2)
    fprintf(stderr, "cd: Too many arguments.\n");
  if (rempl_option(av, option) == -1)
    {
      fprintf(stderr, "Usage: cd [-pl][<dir>].\n");
      return (1);
    }
  else if (count_param(av) == 1)
    {
      if (av[1] != 0)
	{
	 
	}
      else
	return (move_home(av, env, option, &last_cd));
    }
  else
    return (funct_cd_move(av, env, option, &last_cd));
  return (1);
}
