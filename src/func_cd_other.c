/*
** func_cd_other.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 17:53:01 2011 timothee maurin
** Last update Wed May  4 17:59:32 2011 timothee maurin
*/

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

void	change_env(char **av)
{
  char	*pwd;

  pwd = xmalloc(2 * sizeof(*pwd));
  pwd[0] = '/';
  chdir(av[1]);
  pwd = my_pwd(pwd);
  //      my_setenv();
  free(pwd);
}
