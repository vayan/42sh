/*
** main_completion.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 17:58:22 2011 timothee maurin
** Last update Sun May 22 02:34:34 2011 timothee maurin
*/

#include	<string.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	"shell.h"
#include	"prototype.h"
#include	"completion.h"

void			completion(int *i, int *pos, char *buf)
{
  int			tmp;
  int			begin;
  int			type;
  t_completion		*compl;

  tmp = *i;
  xwrite(1, "\n", 1);
  type = which_type(buf, *pos, &begin);
  compl = find_completion(type, buf, *pos, begin);
  traiter_list(compl, buf, i, pos);
  free_list(compl);
  aff_prompt(2);
  *i = strlen(buf);
  *pos += (*i) - tmp;
  my_putstr_del(buf);
  place_cursor(*i, *pos, buf);
}
