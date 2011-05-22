/*
** str_to_wordtab.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Apr 30 13:39:30 2011 maxime constantinian
** Last update Sun May 22 22:05:39 2011 maxime constantinian
*/

#include	<glob.h>
#include	<string.h>
#include	"shell.h"
#include	"prototype.h"

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
	    while (str[++i] && str[i] != '"');
	}
      if (str[i])
	i++;
    }
  return (count_w);
}

char		*clean_word_quote(char *str)
{
  int		i;
  int		j;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == '"')
	{
	  j = i;
	  while (str[j])
	    {
	      str[j] = str[j + 1];
	      if (str[j])
		j++;
	    }
	}
      if (str[i])
	i++;
    }
  return (str);
}

char		**clean_word(char **ret, int *j, int nb_word)
{
  glob_t	paths;
  int		globresult;
  static int	nb_total;
  char		**ret2;
  int		i = -1;

  if (nb_word != 0)
    return ((nb_total = nb_word) * 0);
  if (strcmp(ret[0], "unsetenv") == 0)
    return (ret);
  globresult = glob(ret[*j], 0, NULL, &paths);
  if (globresult == 0)
    {
      ret2 = xmalloc(sizeof(*ret2) * (go_end_env(paths.gl_pathv)
				      + nb_total + 1));
      while (++i < *j)
	ret2[i] = ret[i];
      i = xfree(ret[i]) + xfree(ret) - 1;
      while (paths.gl_pathv[++i])
	ret2[(*j)++] = strdup(paths.gl_pathv[i]);
      (*j)--;
      return (ret2);
    }
  clean_word_quote(ret[*j]);
  return (ret);
}

void		str_to_wordtab_not_quote(char *str, int *i,
					 int *j, char ***ret)
{
  if (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
      && strncmp(&str[*i], "&&", 2) != 0  && strncmp(&str[*i], "||", 2) != 0
      && str[*i] != '|' && strncmp(&str[*i], "<<", 2) != 0 && str[*i] != '<'
      && strncmp(&str[*i], ">>", 2) != 0 && str[*i] != '>')
    {
      (*ret)[*j] = my_strcopynalloc_gen(&str[*i],
					my_strlen_createtab(&str[*i]));
      *ret = clean_word(*ret, j, 0);
      (*j)++;
      while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';'
	     && strncmp(&str[*i], "&&", 2) != 0
	     && strncmp(&str[*i], "||", 2) != 0
	     && str[*i] != '|' && strncmp(&str[*i], "<<", 2) != 0
	     && str[*i] != '<' && strncmp(&str[*i], ">>", 2) != 0
	     && str[*i] != '>')
	{
	  if (str[*i] == '"')
	    {
	      (*i)++;
	      while (str[*i] && str[*i] != '"')
		(*i)++;
	    }
	  if (str[*i])
	    (*i)++;
	}
    }
}

char		**str_to_wordtab(char *str)
{
  int		i = 0;
  int		j = 0;
  char		**ret;
  int		nb_word = count_word(str);

  clean_word(0, 0, nb_word);
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
	str_to_wordtab_not_quote(str, &i, &j, &ret);
    }
  return (ret);
}
