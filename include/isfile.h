/*
** isfile.h for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun Apr 10 18:01:49 2011 maxime constantinian
** Last update Sun Apr 10 18:03:33 2011 maxime constantinian
*/

#ifndef		ISFILE_H__
# define	ISFILE_H__

int		lstat(char *path, struct stat *buf);
int		isfile(char *str);

#endif
