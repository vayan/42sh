/*
** aff_prompt.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Fri May 20 15:37:43 2011 timothee maurin
** Last update Fri May 20 16:24:56 2011 timothee maurin
*/

#include		<string.h>
#include		"shell.h"
#include		"prototype.h"

void			aff_prompt(int test)
{
  static t_shell	*shell;
  static char		*prompt;
  static int		size;

  if (shell == 0)
    shell = recup_shell(0);
  if (test == 0)
    {
      if (prompt != 0)
	free(prompt);
      prompt = 0;
      prompt = get_prompt(shell);
      size = strlen(prompt);
    }
  else if (test == 1)
    {
      free(prompt);
      prompt = 0;
    }
  else
    xwrite(0, prompt, size);
}
