/*
** xdup2.c for mysh in /home/consta_m//minishell2
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun Mar  6 23:22:04 2011 maxime constantinian
** Last update Sun May 22 16:12:02 2011 Vaillant Yann
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>

void		xdup2(int oldfd, int newfd)
{
  if (dup2(oldfd, newfd) == -1)
    fprintf(stderr, "42sh: dup2 : %s\n", strerror(errno));
}
