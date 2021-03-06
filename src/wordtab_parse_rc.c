/*
** str_to_wordtab.c for 42sh in /home/consta_m/prog/42sh/src
**
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
**
** Started on  Sat Apr 30 13:39:30 2011 maxime constantinian
** Last update Sun Jun 12 17:40:26 2011 maxime constantinian
*/

#include	"shell.h"
#include	"prototype.h"

int		count_word_parse(char *str)
{
  int		i = 0;
  int		count_w = 0;
  int		have_space = 1;

  while (str && str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
        have_space = 1;
      else if (have_space == 1)
        {
          have_space = 0;
          count_w++;
          if (str[i] == '"')
            while (str[++i] && str[i] != '"');
        }
      if (str[i])
        i++;
    }
  return (count_w);
}

void		str_to_wordtab_alloc(char *str, int *i, int *j, char **ret)
{
  if (str[*i] && str[*i] != ' ' && str[*i] != '\t')
    {
      ret[*j] = my_strcopynalloc_gen(&str[*i],
				     my_strlen_createtab_rc(&str[*i]));
      (*j)++;
      while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
	(*i)++;
    }
}

char		**str_to_wordtab_parse_rc(char *str)
{
  int		i = 0;
  int		j = 0;
  char		**ret;
  int		nb_word;

  nb_word = count_word_parse(str);
  ret = xmalloc(sizeof(*ret) * (nb_word + 1));
  if (nb_word == 0)
    return (0);
  while (str && str[i] && j < nb_word)
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
	str_to_wordtab_alloc(str, &i, &j, ret);
    }
  return (ret);
}
