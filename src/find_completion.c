/*
** finc_completion.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun May 22 15:39:37 2011 timothee maurin
** Last update Sun May 22 15:40:16 2011 timothee maurin
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

t_completion	*find_completion(int type, char *buf, int pos, int begin)
{
  t_shell	*tmp;

  tmp = recup_shell(0);
  if (type)
    return (find_commande(buf, pos, begin - 1, tmp->tab_hach));
  else
    return (find_in_folder(buf, pos, begin));
}
