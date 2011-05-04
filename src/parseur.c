/*
** parseur.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Apr 26 19:49:14 2011 maxime constantinian
** Last update Wed May  4 03:40:55 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"

void		parser(char *str, t_shell *shell)
{
  int		nb_sep;
  int		i = 0;
  int		j = 0;

  nb_sep = if_have_sep(str);
  shell->commande->cmd = xmalloc(sizeof(*(shell->commande->cmd)));
  if (nb_sep)
    {
      shell->commande->cmd->type = OP_SEP;
      shell->commande->cmd->next = xmalloc(sizeof(char *) * (nb_sep + 2));
      while (str[j] && i < nb_sep + 2)
	{
	  shell->commande->cmd->next[i] = xmalloc(sizeof(t_commande));
	  check_and(&str[j], shell->commande->cmd->next[i]);
	  i++;
	  while (str[j] && str[j] != ';')
	    j++;
	  if (str[j])
	    j++;
	}
    }
  else
    check_and(str, shell->commande->cmd);
}
