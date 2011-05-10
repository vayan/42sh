/*
** recup_shell.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May 10 16:30:28 2011 maxime constantinian
** Last update Tue May 10 16:32:04 2011 maxime constantinian
*/

#include		"shell.h"

t_shell			*recup_shell(t_shell *ptr)
{
  static t_shell	*shell;

  if (ptr != 0)
    shell = ptr;
  return (shell);
}
