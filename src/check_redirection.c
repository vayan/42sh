/*
** check_redirection.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May 10 21:34:38 2011 maxime constantinian
** Last update Sat May 14 13:39:30 2011 maxime constantinian
*/

/* Cree la fonction create_cmd pour le maillon + faire boucler */

#include	"shell.h"
#include	"prototype.h"
#include	"parseur.h"

int		if_have_redirection(char *str)
{
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  while (str[i] && str[i] != ';' && str[i] != '&' && str[i] != '|')
    {
      if (str[i] == '<' || str[i] == '>')
	ret++;
      i++;
    }
  return (ret);
}

int		return_type_red(char *str)
{
  if (strncmp(str, "<<", 2) == 0)
    return (1);
  else if (strncmp(str, ">>", 2) == 0)
    return (2);
  else if (str[0] == '<')
    return (3);
  else if (str[0] == '>')
    return (4);
}

void		create_cmd(char **tab, t_commande *cmd)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  cmd->type = CMD;
  while (tab[i] && !((strlen(tab[i]) == 2
		      && (strncmp(tab[i], "<<", 2) == 0
			  || strncmp(tab[i], ">>", 2) == 0))
		     || (strlen(tab[i]) == 1 && (tab[i][0] == '<'
						 || tab[i][0] == '>'))))
    i++;
    cmd->cmd = xmalloc(sizeof(*(cmd->cmd)) * (i + 1));
  while (j < i)
    {
      cmd->cmd[j] = tab[j];
      j++;
    }
}

t_commande	*create_maillon_red(int type, char **tab, t_commande *cmd)
{
  if (type == 1)
    cmd->type = OP_DRL;
  else if (type == 2)
    cmd->type = OP_DRR;
  else if (type == 3)
    cmd->type = OP_SRL;
  else if (type == 4)
    cmd->type = OP_SRR;
  if (tab[1])
    {
      cmd->next[1] = xmalloc(sizeof(**(cmd->next)));
      cmd->next[1]->type = FILE;
      cmd->next[1]->cmd = xmalloc(sizeof(*(cmd->cmd)) * 2);
      cmd->next[1]->cmd[0] = tab[1];
      if (tab[2]
	  && cmd->next[0] == 0 && !((strlen(tab[2]) == 2
				     && (strncmp(tab[2], "<<", 2) == 0
					 || strncmp(tab[2], ">>", 2) == 0))
				    || (strlen(tab[2]) == 1
					&& (tab[2][0] == '<'
					    || tab[2][0] == '>'))))
	create_cmd(&tab[2], (cmd->next[0] = xmalloc(sizeof(**(cmd->next)))));
      return (cmd->next[1]);
    }
  return (0);
}

void		check_redirection(char *str, t_commande *cmd)
{
  char		**tab;
  int		i;

  i = 0;
  if (if_have_redirection(str))
    {
      tab = str_to_wordtab_red(str);
      if (!((strlen(tab[0]) == 2 && (strncmp(tab[0], "<<", 2) == 0
				     || strncmp(tab[0], ">>", 2) == 0))
	    || (strlen(tab[0]) == 1 && (tab[0][0] == '<'
					|| tab[0][0] == '>'))))
	{
	  if (cmd->next == 0)
	    cmd->next = xmalloc(sizeof(*(cmd->next)) * 3);
	  cmd->next[0] = xmalloc(sizeof(**(cmd->next)));
	  create_cmd(tab, cmd->next[0]);
	  while (!((strlen(tab[i]) == 2 && (strncmp(tab[i], "<<", 2) == 0
					    || strncmp(tab[i], ">>", 2) == 0))
		   || (strlen(tab[i]) == 1 && (tab[i][0] == '<'
					       || tab[i][0] == '>'))))
	    i++;
	}
      while (tab[i])
	{
	  if (cmd->next == 0)
	    cmd->next = xmalloc(sizeof(*(cmd->next)) * 3);
	  if (cmd->type != 0)
	    {
	      cmd->next[1] = xmalloc(sizeof(**(cmd->next)));
	      cmd = cmd->next[1];
	    }
	  if (cmd->next == 0)
	    cmd->next = xmalloc(sizeof(*(cmd->next)) * 3);
	  cmd = create_maillon_red(return_type_red(tab[i]), &tab[i], cmd);
	  i++;
	  while (tab[i] && !((strlen(tab[i]) == 2
			      && (strncmp(tab[i], "<<", 2) == 0
				  || strncmp(tab[i], ">>", 2) == 0))
			     || (strlen(tab[i]) == 1
				 && (tab[i][0] == '<' || tab[i][0] == '>'))))
	    i++;
	}
    }
  else
    check_commande(str, cmd);
}
