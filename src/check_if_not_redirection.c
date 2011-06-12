/*
** check_if_not_redirection.c for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun Jun 12 19:15:05 2011 maxime constantinian
** Last update Sun Jun 12 19:20:34 2011 maxime constantinian
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

int		check_if_not_redirection(char *str)
{
  if (strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0
      || strcmp(str, "<") == 0 || strcmp(str, ">") == 0)
    return (0);
  return (1);
}
