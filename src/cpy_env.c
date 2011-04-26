/*
** cpy_env.c for  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 26 14:59:40 2011 yann vaillant
** Last update Tue Apr 26 19:09:28 2011 maxime constantinian
*/

#include	<stdlib.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

int		get_nbr_ligne_tab(char **env)
{
  int	x = 0;
  
  while (env[x])
    x++;
  return (x);
}

void	copy_env(char **env, t_shell *shell)
{
  int	x = get_nbr_ligne_tab(env);

  shell->env = xmalloc((x + 1) * sizeof(*(shell->env)));
  while (x--)
    shell->env[x] = my_strcopynalloc(env[x]);
}
