/*
** dec_str.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May  3 17:38:24 2011 maxime constantinian
** Last update Tue May  3 18:58:02 2011 maxime constantinian
*/

int		check_if_in(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

void		dec_str(char *str, int *i, char *esc)
{
  while (str[*i] && check_if_in(str[*i], esc) == 0)
    {
      if (str[*i] == '"')
	{
	  while (str[*i] && str[*i] != '"')
	    (*i)++;
	}
      if (str[*i])
	(*i)++;
    }
}
