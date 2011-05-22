/*
** completion.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Thu May 12 13:09:38 2011 timothee maurin
** Last update Sun May 22 02:31:22 2011 timothee maurin
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "shell.h"
#include "prototype.h"
#include "completion.h"

void		add_all_other(t_completion **completion, t_hach_bin *hach)
{
  int		i;

  i = 0;
  while (i < 94)
    {
      if (hach && hach->next && hach->next[i] != 0)
	add_all_other(completion, hach->next[i]);
      i++;
    }
  if (hach->path)
    {
      i = strlen(hach->path);
      while (i > 0 && hach->path[i] != '/')
	i--;
      my_put_in_list(&(hach->path[i + 1]), completion);
    }
}

t_completion	*find_commande(char *buf, int pos, int begin, t_hach_bin *hach)
{
  t_completion	*completion;

  completion = 0;
  while ((begin) < pos && begin != -1)
    {
      if (hach->next && buf[begin] > 32
	  && hach->next[buf[begin] - 32])
	hach = hach->next[buf[begin] - 32];
      else if (buf[begin] > 32)
	begin = -2;
      begin++;
    }
  if (begin != -1)
    add_all_other(&completion, hach);
  return (completion);
}

t_completion	*find_in_folder(char *buf, int pos, int begin)
{
  int		tmp2;
  char		*tmp = 0;
  DIR           *dirp;
  struct dirent *entry;
  t_completion	*completion = 0;

  tmp2 = pos;
  while (buf[tmp2] != '/' && tmp2 > begin && (tmp2-- || 1));
  if ((tmp2 == begin || begin == 0) && buf[tmp2] != '/')
    dirp = xopendir(".");
  else
    {
      while(buf[begin] == 9)
	begin++;
      if (begin < tmp2)
	{
	  tmp = xmalloc((tmp2 - begin + 2) * sizeof(*tmp));
	  strncpy(tmp, &(buf[begin]), tmp2 - begin + 1);
	  tmp[tmp2 - begin + 1] = '\0';
	  dirp = xopendir(tmp);
	}
      else
	dirp = xopendir(".");	
      begin =  tmp2 + 1;
    }
  if (dirp != 0)
    while ((entry = readdir(dirp)) != 0)
      if (!(strncmp(&(buf[begin]), entry->d_name, pos - begin))
	  && (entry->d_name[0] != '.' || buf[begin] == '.'))
	my_put_in_list(entry->d_name, &completion);
  closedir(dirp);
  return (completion);
}

t_completion	*find_completion(int type, char *buf, int pos, int begin)
{
  t_shell	*tmp;

  tmp = recup_shell(0);
  if (type)
    return (find_commande(buf, pos, begin - 1, tmp->tab_hach));
  else
    return (find_in_folder(buf, pos, begin));
}

void		traiter_list(t_completion *compl, char *buf, int *i, int *pos)
{
  int		be;

  if ((be = *pos || 1) && (*pos != 0 || buf[*pos] != ';'))
    while (be > 0 && buf[be] !=  ' ' && buf[be] != 9 && buf[be] != ';')
      be--;
  while (be > 0 && buf[be - 1] == '/')
    be--;
  if (compl)
    {
      if (compl->next)
	{
	  while (compl != 0)
	    {
	      xwrite(0, compl->buf, strlen(compl->buf));
	      is_dir(buf, compl->buf, *pos, be);
	      xwrite(0, "\n", 1);
	      compl = compl->next;
	    }
	}
      else
	{
	  if (compl->buf && *i + strlen(compl->buf) < 8192)
	    put_in_buf(compl->buf, buf, *pos);
	}
    }
}
