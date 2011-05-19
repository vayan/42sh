/*
** my_getnbr.c for clt in /home/consta_m/prog/minitalk/src/clt
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Mar 16 20:12:26 2011 maxime constantinian
** Last update Sat Mar 26 01:53:57 2011 maxime constantinian
*/

int		my_getnbr(char *str)
{
  int		result;
  int		i;
  int		ifneg;

  i = 0;
  result = 0;
  ifneg = 0;
  while (str[i] && str[i] == '-')
    {
      ifneg = 1;
      i++;
    }
  while (str[i] && str[i] >= '0'&& str[i] <= '9')
    {
      result += str[i] - '0';
      i++;
      if (str[i] && str[i] >= '0'&& str[i] <= '9')
	result *= 10;
    }
  if (ifneg == 1)
    result *= -1;
  return (result);
}
