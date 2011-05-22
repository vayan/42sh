/*
** xfree.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun May 22 19:43:26 2011 maxime constantinian
** Last update Sun May 22 19:44:29 2011 maxime constantinian
*/

#include	<stdlib.h>

int		xfree(void *ptr)
{
  free(ptr);
  return (0);
}
