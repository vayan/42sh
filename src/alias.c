/*
** alias.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Mon Jun  6 16:04:30 2011 timothee maurin
** Last update Sun Jun 12 04:30:16 2011 timothee maurin
*/

#include	<string.h>
#include	"shell.h"
#include	"prototype.h"

char		*replace_alias(char *to_place, char *cmd, int dep, int arr)
{
  int		tmp = arr;
  int		i = 0;

  while (to_place && i != -1 && to_place[i] != '\0')
    {
      if (i + dep < arr)
	cmd[i + dep] = to_place[i];
      else
	{
	  my_strcpy_buf(&(cmd[i + dep + strlen(&(to_place[i]))]),
			&(cmd[i + dep]));
	  strncpy(&(cmd[i + dep]), &(to_place[i]), strlen(&(to_place[i])));
	  i = -2;
	}
      i++;
    }
  while (cmd[tmp] != ' ' && cmd[tmp] != 9 && cmd[tmp] != ';' && cmd[tmp] != '|'
	 && cmd[tmp] != '&' && cmd[tmp] != '\0')
    tmp++;
  if (to_place && i + dep < arr && i != -1)
    my_strcpy(&(cmd[dep + i]), &(cmd[tmp]));
  return (cmd);
}

int		already_found(t_list_var *alias, t_list_var *used)
{
  while (alias && alias->name && used->next && strcmp(alias->name, used->name))
    used = used->next;
  if (used->next)
    return (1);
  return (0);
}

t_list_var		*dup_name_var(t_list_var *al, t_list_var *verif)
{
  if (al->name)
    verif->name = strdup(al->name);
  if (al->var)
    verif->var = strdup(al->var);
  return (al);
}

t_list_var	*find_good_alias(t_list_var *al, char *tmp)
{
  t_list_var	*last_one = 0;
  t_list_var	*verif_begin = xmalloc(sizeof(*verif_begin));
  t_list_var	*verif = verif_begin;
  t_list_var	*save = al;

  while (al && al->name && strcmp(al->name, tmp) != 0 && (al = al->next));
  if (al && al->name)
    {
      last_one = dup_name_var(al, verif);
      while (al && al->next && al->next->next != 0 && ((al = save) || 1))
	{
	  while (al && al->next && al->name && verif->var 
		 && strcmp(al->name, verif->var) != 0 && (al = al->next));
	  if (already_found(al, verif_begin))
	    al = 0;
	  else if (al->name && al->var)
	    {
	      verif->next = xmalloc(sizeof(*verif));
	      verif = verif->next;
	      last_one = dup_name_var(al, verif);
	    }
	}
    }
  free_var(verif_begin);
  return (last_one);
}

char		*funct_alias(char *cmd, t_shell *sh, int i)
{
  char		*tmp;
  int		n;
  int		tmp2 = 0;
  t_list_var	*alias = 0;

  while (cmd[i] != '\0')
    {
      while ((cmd[i] == 9 || cmd[i] == ' ' || cmd[i] == ';' || cmd[i] == '|')
	     && cmd[i] != '\0' && ((i = i + 1) || 1));
      n = i;
      while (cmd[i] != 9 && cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|'
	     && cmd[i] != '\0' && (i++ || 1));
      tmp = strndup(&(cmd[n]), i - n);
      if (!(which_type_alias(cmd, n, &tmp2))
	  && check_if_alias(tmp, sh->alias) == 1)
	{
	  alias = find_good_alias(sh->alias, tmp);
	  if (alias && alias->name && alias->var)
	    if (strlen(tmp) + strlen(alias->var) > 0
		&& strlen(tmp) + strlen(alias->var) + strlen(cmd) > 8192)
	      xrealloc(cmd, strlen(tmp) + strlen(alias->var) + strlen(cmd));
	  cmd = replace_alias(alias->var, cmd, n, i);
	}
    }
  return (cmd);
}
