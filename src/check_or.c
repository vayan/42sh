/*
** check_and.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Thu Apr 28 16:44:10 2011 maxime constantinian
** Last update Wed May  4 02:03:36 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"

int		if_have_or(char *str)
{
  int		i = 0;
  int		nb_and = 0;

  if (str == 0)
    return (0);
  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0)
    {
      if (strncmp(&str[i], "||", 2) == 0)
	nb_and++;
      i++;
    }
  return (nb_and);
}

void		check_or(char *str, t_commande *cmd)
{
  int		nb_and;
  int		i = 0;

  nb_and = if_have_or(str);
  if (nb_and)
    {
      cmd->type = OP_OR;
      cmd->next = xmalloc(sizeof(*(cmd->next)) * (3));
      cmd->next[0] = xmalloc(sizeof(t_commande));
      check_pipe(str, cmd->next[0]);
      while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	     && strncmp(&str[i], "||", 2) != 0)
	i++;
      if (strncmp(&str[i], "||", 2) == 0)
	{
	  i += 2;
	  cmd->next[1] = xmalloc(sizeof(t_commande));
	  check_or(&str[i], cmd->next[1]);
	}
    }
  else
    check_pipe(str, cmd);
}
