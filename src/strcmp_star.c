/*
** unsetenv.c for mysh in /home/consta_m/
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Mon Dec 27 14:18:01 2010 maxime constantinian
** Last update Sun May 22 15:31:39 2011 timothee maurin
*/

int		count_star(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while	(str[i])
    {
      if (str[i] == '*')
	count++;
      i++;
    }
  return (count);
}

char		*cmp_str_s(char **tab, char *tmp, int star_start, int star_end)
{
  int		i;
  int		nb_word;

  i = 0;
  nb_word = 0;
  while (tab[i])
    {
      i++;
      nb_word++;
    }
  i = 0;
  while (tab[i] && tmp != 0)
    {
      if (i == 0 && star_start == 0)
	tmp = cmp_star(tmp, tab[i], 0);
      else
	if (i == nb_word - 1 && star_end == 0)
	  tmp = cmp_star(tmp, tab[i], 1);
	else
	  if (tmp != 0)
	    tmp = my_strstr(tmp, tab[i]);
      i++;
    }
  return (tmp);
}

int		my_strcmp_star(char *s1, char *s2)
{
  char		**tab;
  char		*tmp;
  int		star_start;
  int		star_end;

  if (count_star(s1) == 0)
    {
      if (strcmp(s1, s2) == 0)
	return (0);
      else
	return (1);
    }
  star_start = 0;
  star_end = 0;
  if (s1[0] == '*')
    star_start = 1;
  if (s1[strlen(s1) - 1] == '*')
    star_end = 1;
  tab = my_str_to_wordtab_star(s1);
  tmp = cmp_str_s(tab, s2, star_start, star_end);
  free_tab(tab);
  if (tmp == 0)
    return (1);
  return (0);
}
