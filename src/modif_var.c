/*
** modif_var.c for  in /home/vailla_y/Projet/42shtest/src
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue May 17 17:18:58 2011 Vaillant Yann
** Last update Tue May 17 17:24:17 2011 Vaillant Yann
*/

#include <string.h>
#include "shell.h"

t_list_var      *update_var_in_list(char **name_var, t_list_var *list_var)
{
  t_list_var *temp = list_var;

  while (temp->next != NULL && name_var[1]  && name_var[2])
    {
      if (strcmp(name_var[1], temp->name) == 0)
        {
          temp->var = name_var[2];
          return (temp);
        }
      temp = temp->next;
    }
  return (temp);
}

t_list_var      *add_var_to_list(char **name_var, t_list_var *list_var)
{
  t_list_var *new;

  if (name_var[1] != NULL && name_var[2] != NULL)
    {
      list_var->name = name_var[1];
      list_var->var = name_var[2];
      new = malloc(sizeof(t_list_var));
      list_var->next = new;
      new->next = 0;
      list_var = list_var->next;
    }
  return (list_var);
}

t_list_var      *remove_var_in_list(char *name_var, t_list_var *list_var)
{
  t_list_var *temp = list_var;

  if (strcmp(temp->name, name_var) == 0)
    return (temp->next);
  while (temp->next->next)
    {
      if (temp->next->next == NULL &&
          (strcmp(temp->next->name, name_var) == 0))
        {
          temp->next = NULL;
          return (temp->next);
        }
      if (strcmp(temp->next->name, name_var) == 0)
        {
          temp->next = temp->next->next;
          return (temp->next);
        }
      temp = temp->next;
    }
  return (temp->next);
}
