/*
** my_signal.c for 42sh in /home/maurin_t//42sh
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Thu May  5 17:31:36 2011 timothee maurin
** Last update Tue May 10 21:35:43 2011 timothee maurin
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"prototype.h"

void            funct_exit(int sig)
{
  sig = sig;
  xwrite(0, "\b\b  \b\b", 6);
}

void            funct_noexit(int sig)
{
  sig = sig;
}
