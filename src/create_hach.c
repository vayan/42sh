/*
** test.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr  6 12:29:25 2011 maxime constantinian
** Last update Mon Apr 11 15:52:11 2011 maxime constantinian
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>
#include	"graph.h"
#include	"xmalloc.h"
#include	"snprintf.h"
#include	"isfile.h"

char		*recup_hach(t_hach_bin *tab, char *name)
{
  int		i;

  i = 0;
  while (name[i])
    {
      if (tab->next == NULL || tab->next[name[i] - 32] == NULL)
	return (NULL);
      else
	tab = tab->next[name[i] - 32];
      i++;
    }
  return (tab->path);
}

t_hach_bin	*create_hach_tab(struct dirent *read_d, t_hach_bin *tmp)
{
  int		i;

  i = 0;
  while (read_d->d_name[i])
    {
      if (tmp->next == NULL)
	tmp->next = xmalloc(94 * sizeof(*(tmp->next)));
      if (tmp->next[read_d->d_name[i] - 32] == NULL)
	{
	  tmp->next[read_d->d_name[i] - 32] = xmalloc(sizeof(*tmp));
	}
      tmp = tmp->next[read_d->d_name[i] - 32];
      i++;
    }
  return (tmp);
}

void		create_hach(char *path, t_hach_bin *tab)
{
  char		*tmp_path;
  t_hach_bin	*tmp;
  DIR		*dir;
  struct dirent	*read_d;

  dir = opendir(path);
  if (dir == NULL)
    return ;
  while ((read_d = readdir(dir)) != NULL)
    {
      tmp_path = xmalloc(strlen(path) + strlen(read_d->d_name) + 2);
      snprintf(tmp_path, strlen(path) + strlen(read_d->d_name) + 2,
	       "%s/%s", path, read_d->d_name);
      if (read_d->d_name[0] != '.' && isfile(tmp_path))
	{
	  tmp = tab;
	  tmp = create_hach_tab(read_d, tmp);
	  tmp->path = tmp_path;
	}
      else
	free(tmp_path);
    }
  if (closedir(dir) == -1)
    fprintf(stderr, "42sh: Invalid directory stream descriptor\n");
}
