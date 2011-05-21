/*
** my_str_to_wordtab.c for mysh in /home/consta_m//minish
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Mon Dec 27 11:39:11 2010 maxime constantinian
** Last update Sat May 21 20:30:15 2011 maxime constantinian
*/

int		countword_star(char *s)
{
  int		count;
  int		i;
  int		havespace;

  i = 0;
  count = 0;
  havespace = 1;
  while (s[i])
    {
      while (s[i] == '*')
	{
	  havespace = 1;
	  i++;
	}
      if (havespace == 1 && s[i] != 0)
	{
	  count++;
	  havespace = 0;
	}
      if (s[i] != 0)
	i++;
    }
  return (count);
}

char		*my_strcopynalloc_star(char *dest, char *source)
{
  int		i;

  i = 0;
  dest = xmalloc(my_strlen_star(source) + 1);
  while (source[i] != '*' && source[i])
    {
      dest[i] = source[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char		**my_str_to_wordtab_star(char *s)
{
  char		**tab;
  char		*tmp;
  int		size;
  int		i;
  int		count;

  tmp = 0;
  i = 0;
  count = 0;
  size = countword_star(s);
  tab = xmalloc(sizeof(*tab) * (size + 1));
  while (s[i])
    {
      while (s[i] == '*')
	i++;
      if (s[i] != 0)
	{
	  tab[count] = my_strcopynalloc_star(tmp, &s[i]);
	  count++;
	}
      while (s[i] != '*' && s[i])
	i++;
    }
  tab[count] = 0;
  return (tab);
}
