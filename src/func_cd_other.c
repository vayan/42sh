/*
** func_cd_other.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 17:53:01 2011 timothee maurin
** Last update Mon May 23 11:59:29 2011 timothee maurin
*/

#include	<errno.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

int	write_error(char *to_write, char *param)
{
  fprintf(stderr, to_write, param);
  return (1);
}

int	count_param(char **av)
{
  int	i;

  i  = 0;
  while (av[i] != 0 && (av[i][0] != '-' || av[i][1] == '\0'))
    i++;
  return (i);
}

void	change_env(char **env, int *tab)
{
  char	**pwd;

  pwd = xmalloc(4 * sizeof(*pwd));
  pwd[0] = xmalloc(7 * sizeof(**pwd));
  pwd[1] = xmalloc(4 * sizeof(**pwd));
  pwd[2] = xmalloc(2 * sizeof(**pwd));
  pwd[2][0] = '/';
  pwd[0][0] = 's';
  pwd[0][1] = 'e';
  pwd[0][2] = 't';
  pwd[0][3] = 'e';
  pwd[0][4] = 'n';
  pwd[0][5] = 'v';
  pwd[0][6] = '\0';
  pwd[1][0] = 'P';
  pwd[1][1] = 'W';
  pwd[1][2] = 'D';
  pwd[1][3] = '\0';
  pwd[2] = my_pwd(pwd[2]);
  pwd[3] = 0;
  my_setenv(pwd, env, tab);
  free(pwd[0]);
  free(pwd[1]);
  free(pwd[2]);
  free(pwd);
}

char		*func_old_pwd(int test)
{
  static char	*pwd;

  if (test == 1)
    {
      if (pwd)
	free(pwd);
      pwd = xmalloc(2 * sizeof(*pwd));
      pwd[0] = '/';
      pwd = my_pwd(pwd);
    }
  if (test == 2 && pwd)
    {
      free(pwd);
      pwd = 0;
    }
  if (pwd)
    return (strdup(pwd));
  else
    return (0);
}

int	change_dir(char **av, char **env, int *tab)
{
  if (chdir(av[1]) == -1)
    return (fprintf(stderr, "42sh: Cd : %s\n", strerror(errno)));
  change_env(env, tab);
  return (0);
}
