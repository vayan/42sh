/*
** exec_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 02:16:59 2011 maxime constantinian
** Last update Sat May 21 17:25:18 2011 maxime constantinian
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/resource.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

int		srd_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		fd = -1;

  if (tab[1] != 0)
    return (fprintf(stderr, "42sh: Ambiguous output redirect.\n") * 0 + 127);
  if (cmd->next[1])
    {
      if (access(cmd->next[1]->cmd[0], F_OK) == -1)
	fd = open(cmd->next[1]->cmd[0], O_CREAT | O_WRONLY,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      else
	fd = open(cmd->next[1]->cmd[0], O_WRONLY | O_TRUNC,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    }
  if (fd != -1)
    {
      tab[1] = fd;
      if (cmd->next[1]->next && cmd->next[1]->next[1])
	exec_type_cmd(cmd->next[1]->next[1], shell, tab);
      if (cmd->next[0])
	exec_type_cmd(cmd->next[0], shell, tab);
    }
}

int		drd_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		fd = -1;

  if (tab[1] != 0)
    return (fprintf(stderr, "42sh: Ambiguous output redirect.\n") * 0 + 127);
  if (cmd->next[1])
    {
      if (access(cmd->next[1]->cmd[0], F_OK) == -1)
	fd = open(cmd->next[1]->cmd[0], O_CREAT | O_WRONLY,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      else
	fd = open(cmd->next[1]->cmd[0], O_WRONLY | O_APPEND,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    }
  if (fd != -1)
    {
      tab[1] = fd;
      if (cmd->next[1]->next && cmd->next[1]->next[1])
	exec_type_cmd(cmd->next[1]->next[1], shell, tab);
      if (cmd->next[0])
	exec_type_cmd(cmd->next[0], shell, tab);
    }
  return (0);
}

int		srl_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		fd = -1;

  if (tab[0] != 0)
    return (fprintf(stderr, "42sh: Ambiguous output redirect.\n") * 0 + 127);
  if (cmd->next[1])
    {
      if (access(cmd->next[1]->cmd[0], F_OK) != -1)
	fd = open(cmd->next[1]->cmd[0], O_RDONLY);
      else
	fprintf(stderr, "42sh: %s %s\n", cmd->next[1]->cmd[0],
		(char*)strerror(errno));
    }
  if (fd != -1)
    {
      tab[0] = fd;
      if (cmd->next[1]->next && cmd->next[1]->next[1])
	exec_type_cmd(cmd->next[1]->next[1], shell, tab);
      if (cmd->next[0])
	exec_type_cmd(cmd->next[0], shell, tab);
    }
  return (0);
}

int             fill_file_drl(t_commande *cmd, int fd)
{
  char          *tmp;

  if (fd == -1)
    fprintf(stderr, "42sh: Open failed.\n");
  else
    {
      xwrite(0, "?", 1);
      while (strcmp((tmp = get_next_line(0)), cmd->next[1]->cmd[0]) != 0)
        {
          xwrite(fd, tmp, strlen(tmp));
	  xwrite(fd, "\n", 1);
	  xwrite(0, "?", 1);
          free(tmp);
        }
      close (fd);
      fd = open("/tmp/azorox", O_RDONLY);
    }
  return (fd);
}

int		drl_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		fd = -1;

  if (tab[0] != 0)
    return (fprintf(stderr, "42sh: Ambiguous output redirect.\n") * 0 + 127);
  if (cmd->next[1])
    {
      if (access("/tmp/azorox", F_OK) == -1)
	fd = open("/tmp/azorox", O_CREAT | O_WRONLY,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      else
	fd = open("/tmp/azorox", O_TRUNC | O_WRONLY,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      fd = fill_file_drl(cmd, fd);
    }
  if (fd != -1)
    {
      tab[0] = fd;
      if (cmd->next[1]->next && cmd->next[1]->next[1])
	exec_type_cmd(cmd->next[1]->next[1], shell, tab);
      if (cmd->next[0])
	exec_type_cmd(cmd->next[0], shell, tab);
    }
  return (0);
}
