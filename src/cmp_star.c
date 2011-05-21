/*
** cmp_star.c for mysh in /home/consta_m/
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Dec 28 12:44:42 2010 maxime constantinian
** Last update Sat May 21 20:29:43 2011 maxime constantinian
*/

char		*cmp_star(char *s1, char *s2, int pos)
{
  int		lens2;
  int		lens1;
  int		i;

  i = 0;
  lens2 = my_strlen(s2);
  lens1 = my_strlen(s1);
  if (pos == 0)
    while (i < lens2)
      {
	if (s1[i] != s2[i])
	  return (0);
	i++;
      }
  else
    while (i < lens2)
      {
	if (s1[lens1 - lens2 + i] != s2[i])
	  return (0);
	i++;
      }
  return (&s1[i]);
}
