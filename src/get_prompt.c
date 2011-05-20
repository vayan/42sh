/*
** set_prompt.c for  in /home/vailla_y//Projet/42shtest
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May 18 17:02:52 2011 yann vaillant
** Last update Fri May 20 16:22:48 2011 timothee maurin
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "xmalloc.h"

char	*test_balise(char *prompt, int i)
{
  if (prompt[i] == '%' && prompt[i + 1] == 'T')
    return (time_system());
  if (prompt[i] == '%' && prompt[i + 1] == '*')
    return (time_system_sec());
  if (prompt[i] == '%' && prompt[i + 1] == 'D')
    return (date_system());
  if (prompt[i] == '%' && prompt[i + 1] == 'n')
    return (pseudo_user());
  if (prompt[i] == '%' && prompt[i + 1] == 'N')
    return (real_name());
  if (prompt[i] == '%' && prompt[i + 1] == 'd')
    return (current_folder());
  if (prompt[i] == '%' && prompt[i + 1] == '~')
    return (folder_to_home());
  if (prompt[i] == '%' && prompt[i + 1] == 'M')
    return (name_host_pc());
  if (prompt[i] == '%' && prompt[i + 1] == 'l')
    return (current_shell());
  return (NULL);
}

int	add_to_prompt(char **format_prompt, char **temp, int *z, int *i)
{
  *z = strlen(*format_prompt) + 2;
  *format_prompt = realloc(*format_prompt,
			   (*z + strlen(*temp) * sizeof(char)));
  (*format_prompt)[(*z) + 1] = '\0';
  strcat(*format_prompt, *temp);
  free(*temp);
  (*i)++;
  return (0);
}

char	*parse_prompt(char *prompt)
{
  int	i = 0;
  int	x = 0;
  int	z = 0;
  char	*format_prompt = xmalloc(strlen(prompt) * sizeof(char));
  char	*temp;

  while (prompt[i])
    {
      temp = test_balise(prompt, i);
      if (temp != NULL)
	add_to_prompt(&format_prompt, &temp, &z, &i);
      else if (prompt[i])
	{
	  x = strlen(format_prompt);
	  format_prompt = realloc(format_prompt, (x + 2 * sizeof(char)));
	  format_prompt[x] = prompt[i];
	  format_prompt[x + 1] = '\0';
	}
      i++;
    }
  return (format_prompt);
}

char		*get_prompt(t_shell *shell)
{
  t_list_var	*var = shell->variable;
  char		*prompt;

  while (var && var->next)
    {
      if (strcmp(var->name, "PROMPT") == 0)
	{
	  prompt = xmalloc(strlen(var->var) + 1 * sizeof(*prompt));
	  strcpy(prompt, var->var);
	  if (prompt[0])
	    prompt = parse_prompt(prompt);
	  return (prompt);
	}
      var = var->next;
    }
  return ("$>");
}
