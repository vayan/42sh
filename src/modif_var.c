/*
** modif_var.c for  in /home/vailla_y/Projet/42shtest/src
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue May 17 17:18:58 2011 Vaillant Yann
** Last update Sun Jun 12 03:25:18 2011 timothee maurin
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "prototype.h"

t_list_var      *update_var_in_list(char **name_var, t_list_var *list_var)
{
  t_list_var *temp = list_var;

  while (temp->next != NULL && name_var[1] && name_var[2])
    {
      if (strcmp(name_var[1], temp->name) == 0)
        {
	  free(temp->var);
          temp->var = strdup(name_var[2]);
          return (temp);
        }
      temp = temp->next;
    }
  return (temp);
}

t_list_var      *add_var_to_list(char **name_var, t_list_var *list_var)
{
  t_list_var *new;

  if (name_var[1] != NULL)
    {
      list_var->name = strdup(name_var[1]);
      if (name_var[2])
	list_var->var = strdup(name_var[2]);
      new = xmalloc(sizeof(t_list_var));
      list_var->next = new;
      new->next = 0;
      list_var = list_var->next;
    }
  return (list_var);
}

void		free_maillon_var(t_list_var *tmp)
{
  if (tmp)
    {
      if (tmp->name)
	free(tmp->name);
      if (tmp->var)
	free(tmp->var);
      free(tmp);
    }
}

t_list_var      *remove_var_in_list(char *name_var, t_list_var **list_var,
				    t_list_var *temp)
{
  t_list_var	*tmp;

  if (strcmp(temp->name, name_var) == 0)
    {
      *list_var = (*list_var)->next;
      free_maillon_var(temp);
      return (*list_var);
    }
  while (temp->next->next)
    {
      if (temp->next->next == NULL &&
          (strcmp(temp->next->name, name_var) == 0))
        {
	  free_maillon_var(temp->next);
          return ((temp->next =  NULL));
        }
      if (strcmp(temp->next->name, name_var) == 0 && ((tmp = temp->next) || 1))
        {
	  temp->next = temp->next->next;
	  free_maillon_var(tmp);
          return (temp->next);
        }
      temp = temp->next;
    }
  return (temp->next);
}
