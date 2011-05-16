/*
** str_to_wordtab.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Apr 30 13:39:30 2011 maxime constantinian
** Last update Mon May 16 19:00:09 2011 maxime constantinian
*/

#include	<string.h>
#include	"shell.h"
#include	"prototype.h"

void		move_red(char *str, int *i, int *have_space)
{
  if (str[*i] == '<' || str[*i] == '>')
    {
      (*have_space) = 1;
      if (strncmp(&str[*i], "<<", 2) == 0
	  || strncmp(&str[*i], ">>", 2) == 0)
	*i += 1;
    }
}

int		count_word_red(char *str)
{
  int		i = 0;
  int		count_w = 0;
  int		have_space = 1;

  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	 && strncmp(&str[i], "||", 2) != 0 && str[i] != '|')
    {
      if (str[i] == ' ' || str[i] == '\t')
	have_space = 1;
      else if (have_space == 1 || str[i] == '<' || str[i] == '>')
	{
	  have_space = 0;
	  count_w++;
	  if (str[i] == '"')
	    {
	      i++;
	      while (str[i] && str[i] != '"')
		i++;
	    }
	  move_red(str, &i, &have_space);
	}
      if (str[i])
	i++;
    }
  return (count_w);
}

void		str_to_wordtab_not_quote_if_red(char *str, int *i,
						int *j, char **ret)
{
  if (strncmp(&str[*i], "<<", 2) == 0
      || strncmp(&str[*i], ">>", 2) == 0)
    {
      ret[*j] = my_strcopynalloc_gen(&str[*i], 2);
      *i += 2;
    }
  else
    {
      ret[*j] = my_strcopynalloc_gen(&str[*i], 1);
      *i += 1;
    }
  *j += 1;
}

void		str_to_wordtab_not_quote_red(char *str, int *i,
					     int *j, char **ret)
{
  if (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
      && strncmp(&str[*i], "&&", 2) != 0  && strncmp(&str[*i], "||", 2) != 0
      && str[*i] != '|')
    {
      if (str[*i] == '<' || str[*i] == '>')
	str_to_wordtab_not_quote_if_red(str, i, j, ret);
      else
	{
	  ret[*j] = my_strcopynalloc_gen(&str[*i],
					 my_strlen_createtab(&str[*i]));
	  (*j)++;
	  while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
		 && strncmp(&str[*i], "&&", 2) != 0
		 && strncmp(&str[*i], "||", 2) != 0
		 && str[*i] != '|' && str[*i] != '<' && str[*i] != '>')
	    (*i)++;
	}
    }
}

char		**str_to_wordtab_red(char *str)
{
  int		i = 0;
  int		j = 0;
  char		**ret;
  int		nb_word;

  nb_word = count_word_red(str);
  ret = xmalloc(sizeof(*ret) * (nb_word + 1));
  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	 && strncmp(&str[i], "||", 2) != 0 && str[i] != '|')
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      if (str[i] == '"')
	{
	  i++;
	  ret[j++] = my_strcopynalloc_gen(&str[i], my_strlen_quote(&str[i]));
	  while (str[i] && str[i] != '"')
	    i++;
	  i++;
	}
      else
	str_to_wordtab_not_quote_red(str, &i, &j, ret);
    }
  return (ret);
}
