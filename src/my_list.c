/*
** my_list.c for my_list in /home/maurin_t//minishell
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Mon Jan  3 15:50:32 2011 timothee maurin
** Last update Sun May 22 15:46:45 2011 timothee maurin
*/

#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	"shell.h"
#include	"prototype.h"
#include	"completion.h"

int			my_put_in_list(char *buf, t_completion **list)
{
  int			i;
  t_completion		*element;
  static t_completion	*save;

  element = 0;
  i = 0;
  if (*list == 0)
    save = 0;
  element = xmalloc(sizeof(*element));
  element->buf =  xmalloc((strlen(buf) + 1)* sizeof(*(element->buf)));
  if (save == '\0')
    *list = element;
  if (element == 0)
    return (1);
  while (buf[i] != '\0')
    {
      element->buf[i] = buf[i];
      i++;
    }
  element->buf[i] = '\0';
  if (save != '\0')
    save->next = element;
  save = element;
  return (0);
}

t_completion	*free_list(t_completion *list)
{
  if (list)
    {
      if (list->next != 0)
	free_list(list->next);
      free(list->buf);
      free(list);
    }
  return (0);
}
