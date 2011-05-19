/*
** main_completion.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 17:58:22 2011 timothee maurin
** Last update Thu May 19 14:30:39 2011 timothee maurin
*/

#include	"shell.h"
#include	"prototype.h"
#include	"completion.h"

void            completion(int *i, int *pos, char *buf)
{
  int		tmp;
  int           begin;
  int           type;
  t_completion  *compl;

  tmp = *i;
  xwrite(1, "\n", 1);
  type = which_type(buf, *pos, &begin);
  compl = find_completion(type, buf, *pos, begin);
  traiter_list(compl, buf, i, pos);
  xwrite(0, "$>", 2);
  *i = strlen(buf);
  *pos += (*i) - tmp;
  my_putstr_del(buf);
  place_cursor(*i, *pos, buf);
}