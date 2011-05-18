/*
** my_list.c for my_list in /home/maurin_t//minishell
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Mon Jan  3 15:50:32 2011 timothee maurin
** Last update Wed May 18 16:59:21 2011 timothee maurin
*/

#include	<string.h>
#include	<stdlib.h>
#include	"completion.h"
#include	"shell.h"
#include	"prototype.h"

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

struct s_list	*free_list(t_completion *list)
{
  if (list->next != 0)
    {
      free_list(list->next);
      free(list);
    }
  return (0);
}
