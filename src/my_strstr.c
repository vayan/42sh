/*
** my_strstr.c for Jour_06 in /home/consta_m//Jour_06
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Mon Oct 11 18:36:37 2010 maxime constantinian
** Last update Sat May 21 21:19:57 2011 Vaillant Yann
*/

char		*my_strstr(char *str, char *to_find)
{
  int		zergling;
  int		ultralisk;
  int		cafard;

  zergling = 0;
  ultralisk = 0;
  cafard = 0;
  while (str[zergling] != '\0')
    {
      if (str[zergling] == to_find[ultralisk])
	ultralisk = ultralisk + 1;
      else
	{
	  cafard = ultralisk + cafard + 1;
	  ultralisk = 0;
	}
      if (to_find[ultralisk] == '\0')
	return (str + cafard + strlen(to_find));
      zergling = zergling + 1;
    }
  return (0);
}
