/*
** str_to_wordtab.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Apr 30 13:39:30 2011 maxime constantinian
** Last update Wed May  4 11:23:38 2011 maxime constantinian
*/

#include	"shell.h"

int		count_word(char	*str)
{
  int		i = 0;
  int		count_w = 0;
  int		have_space = 1;

  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	 && strncmp(&str[i], "||", 2) != 0 && str[i] != '|'
	 && strncmp(&str[i], "<<", 2) != 0 && str[i] != '<'
	 && strncmp(&str[i], ">>", 2) != 0 && str[i] != '>')
    {
      if (str[i] == ' ' || str[i] == '\t')
	have_space = 1;
      else if (have_space == 1)
	{
	  have_space = 0;
	  count_w++;
	  if (str[i] == '"')
	    {
	      i++;
	      while (str[i] && str[i] != '"')
		i++;
	    }
	}
      if (str[i])
	i++;
    }
  return (count_w);
}

void		str_to_wordtab2(char *str, int *i, int *j, char **ret)
{
  if (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
      && strncmp(&str[*i], "&&", 2) != 0  && strncmp(&str[*i], "||", 2) != 0
      && str[*i] != '|' && strncmp(&str[*i], "<<", 2) != 0 && str[*i] != '<'
      && strncmp(&str[*i], ">>", 2) != 0 && str[*i] != '>')
    {
      ret[*j] = my_strcopynalloc_gen(&str[*i], my_strlen_createtab(&str[*i]));
      (*j)++;
      while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
	     && strncmp(&str[*i], "&&", 2) != 0
	     && strncmp(&str[*i], "||", 2) != 0
	     && str[*i] != '|' && strncmp(&str[*i], "<<", 2) != 0
	     && str[*i] != '<' && strncmp(&str[*i], ">>", 2) != 0
	     && str[*i] != '>')
	(*i)++;
    }
}

char		**str_to_wordtab(char *str)
{
  int		i = 0;
  int		j = 0;
  char		**ret;
  int		nb_word;

  nb_word = count_word(str);
  ret = xmalloc(sizeof(*ret) * (nb_word + 1));
  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	 && strncmp(&str[i], "||", 2) != 0 && str[i] != '|'
	 && strncmp(&str[i], "<<", 2) != 0 && str[i] != '<'
	 && strncmp(&str[i], ">>", 2) != 0 && str[i] != '>')
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
	str_to_wordtab2(str, &i, &j, ret);
    }
  return (ret);
}
