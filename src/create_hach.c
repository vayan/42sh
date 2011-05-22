/*
** test.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr  6 12:29:25 2011 maxime constantinian
** Last update Sun May 22 15:36:21 2011 timothee maurin
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"
#include	"graph.h"
#include	"parseur.h"
#include	"prototype.h"

char		*recup_hach(t_hach_bin *tab, char *name)
{
  int		i;

  i = 0;
  while (name && tab && name[i])
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
	tmp->next[read_d->d_name[i] - 32] = xmalloc(sizeof(*tmp));
      tmp = tmp->next[read_d->d_name[i] - 32];
      i++;
    }
  return (tmp);
}

void		create_hach(char *path, t_hach_bin *tab)
{
  char		*tmp_path;
  t_hach_bin	*tmp;
  DIR		*dir = opendir(path);
  struct dirent	*read_d;

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
	  if (tmp->path != 0)
	    free(tmp->path);
	  tmp->path = tmp_path;
	}
      else
	free(tmp_path);
    }
  if (closedir(dir) == -1)
    fprintf(stderr, "42sh: Invalid directory stream descriptor\n");
}

char		*strcpynalloc_hach(char *str)
{
  int		i;
  int		len;
  char		*ret;

  i = 0;
  len = my_strlen_hach(str);
  if (len == 0)
    return (NULL);
  ret = xmalloc(len + 1);
  while (i < len)
    {
      ret[i] = str[i];
      i++;
    }
  return (ret);
}

void		add_hachtab_to_shell(t_shell *shell)
{
  char		*ret;
  char		*ret2;
  int		i = 0;

  ret = my_get_env("PATH", shell->env);
  shell->tab_hach = xmalloc(sizeof(*(shell->tab_hach)));
  if (ret)
    {
      while (ret[i])
	{
	  ret2 = strcpynalloc_hach(&ret[i]);
	  if (ret2)
	    {
	      create_hach(ret2, shell->tab_hach);
	      free(ret2);
	    }
	  while (ret[i] && ret[i] != ':')
	    i++;
	  if (ret[i] == ':')
	    i++;
	}
      free(ret);
    }
}
