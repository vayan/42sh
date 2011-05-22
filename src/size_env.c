/*
** size_env.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun May 22 15:42:14 2011 timothee maurin
** Last update Sun May 22 15:42:18 2011 timothee maurin
*/

int     size_env(char **av)
{
  int   i = 0;

  while (av[i])
    i++;
  return (i);
}
