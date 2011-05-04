/*
** if_have_sep.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr 27 00:09:08 2011 maxime constantinian
** Last update Wed May  4 03:44:03 2011 maxime constantinian
*/

int		if_have_sep(char *str)
{
  int		i;
  int		nb_sep;

  nb_sep = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '"')
	while (str[i] && str[i] != '"')
	  i++;
      if (str[i] == ';')
	nb_sep++;
      if (str[i])
	i++;
    }
  return (nb_sep);
}
