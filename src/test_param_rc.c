/*
** test_param_rc.c for  in /home/vailla_y/Projet/42shtest/src
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue May 17 17:24:58 2011 Vaillant Yann
** Last update Sun May 22 01:41:16 2011 timothee maurin
*/

#include <string.h>
#include "shell.h"
#include "prototype.h"

void    test_set(char **name_var, t_list_var **buffer, t_list_var **list_var)
{
  if (strcmp(name_var[0], "set") == 0 &&
      check_if_exist_in_list(name_var[1], *buffer) == 0)
    *list_var = add_var_to_list(name_var, *list_var);
  else if (strcmp(name_var[0], "set") == 0 &&
           check_if_exist_in_list(name_var[1], *buffer) == 1)
    *list_var = update_var_in_list(name_var, *buffer);
}

void    test_alias(char **name_var, t_list_var **alias_buf,
                   t_list_var **alias)
{
  if (strcmp(name_var[0], "alias") == 0 &&
      check_if_exist_in_list(name_var[1], *alias_buf) == 0)
    *alias = add_var_to_list(name_var, *alias);
  else if (strcmp(name_var[0], "alias") == 0 &&
           check_if_exist_in_list(name_var[1], *alias_buf) == 1)
    *alias = update_var_in_list(name_var, *alias_buf);
}

void    test_unset(char **name_var, t_list_var **buffer)
{
  if (strcmp(name_var[0], "unset") == 0 &&
      check_if_exist_in_list(name_var[1], *buffer) == 1)
    remove_var_in_list(name_var[1], *buffer);
}
