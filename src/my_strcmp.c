/*
** my_strcmp.c for my_strcmp in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
**
** Started on  Mon Oct 11 11:35:59 2010 timothee maurin
** Last update Sun Jan  9 01:42:59 2011 timothee maurin
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      i++;
      if (s1[i] == '\0' && s2[i] == '\0')
	return (1);
      if (s1[i] == '\0' || s2[i] == '\0')
	return (0);
    }
  return (0);
}

int     my_strcmpbis(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      i++;
      if (s1[i] == '\0')
        return (1);
      if (s1[i] == '\0' || s2[i] == '\0')
        return (0);
    }
  return (0);
}

void	funct_while(int *i, int *n, char *s1, char *s2)
{
  (*i)++;
  while (s1[*i] != s2[*n] && s2[*n] != '\0')
    (*n)++;
}

int     my_strcmpre(char *s1, char *s2)
{
  int   i;
  int	n;

  n = 0;
  i = 0;
  if (s1[i] == '*')
    funct_while(&i, &n, s1, s2);
  while (s1[i] == s2[n] && s1[i] != '\0' && s2[n] != '\0')
    {
      n++;
      i++;
      if (s1[i] == '*')
	funct_while(&i, &n, s1, s2);
      if (s1[i] == '\0' || s1[i - 1] == '\0')
	return (1);
      if (s1[i] == '\0' || s2[n] == '\0')
	return (0);
    }
  return (0);
}

int     my_strcmpspecial(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      i++;
      if (s1[i + 1] == '\0')
        return (1);
      if (s1[i] == '\0' || s2[i] == '\0')
        return (0);
    }
  return (0);
}
