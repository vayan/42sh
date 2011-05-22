/*
** my_strlen_star.c for  in /home/vailla_y/Projet/42shtest
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Sat May 21 21:23:32 2011 Vaillant Yann
** Last update Sun May 22 15:29:52 2011 timothee maurin
*/

int	my_strlen_star(char *str)
{
  int	i  = 0;

  while (str[i] != '*' && str[i])
    i++;
  return (i);
}
