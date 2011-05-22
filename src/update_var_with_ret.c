/*
** update_var_with_ret.c for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun May 22 15:59:52 2011 maxime constantinian
** Last update Sun May 22 16:26:56 2011 maxime constantinian
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"shell.h"
#include	"prototype.h"

int		len_ret(int ret)
{
  int		len = 0;

  if (ret == 0)
    return (1);
  while (ret)
    {
      len++;
      ret = ret / 10;
    }
  return (len);
}

void		update_var_with_ret(int ret)
{
  char		*buff;
  int		len;
  char		*ta[3];
  int		tab[2];

  len = len_ret(ret);
  buff = xmalloc(2 + len + 1);
  snprintf(buff, 2 + len + 1, "?=%d", ret);
  ta[0] = "set";
  ta[1] = buff;
  ta[2] = 0;
  tab[0] = 0;
  tab[1] = 0;
  my_set(ta, tab);
  free(buff);
}
