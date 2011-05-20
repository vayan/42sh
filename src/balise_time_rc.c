/*
** balise_time_rc.c for  in /home/vailla_y/Projet/42shtest/src
**
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
**
** Started on  Fri May 20 11:06:39 2011 Vaillant Yann
** Last update Fri May 20 11:08:24 2011 Vaillant Yann
*/

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "xmalloc.h"

char    *time_system()
{
  time_t timestamp;
  struct tm * tm;
  char  *hour = xmalloc(10 * sizeof(char));
  char  *min = xmalloc(10 * sizeof(char));
  char  *hhmm;

  timestamp = time(NULL);
  tm = localtime(&timestamp);
  snprintf(hour, 10, "%02d", tm->tm_hour);
  snprintf(min, 10, "%02d", tm->tm_min);
  hhmm = xmalloc((strlen(hour) + strlen(min) + 2) * sizeof(char));
  strcat(hhmm, hour);
  strcat(hhmm, ":");
  strcat(hhmm, min);
  free(hour);
  free(min);
  return (hhmm);
}

char    *time_system_sec()
{
  time_t timestamp;
  struct tm * tm;
  char  *hour = xmalloc(10 * sizeof(char));
  char  *min = xmalloc(10 * sizeof(char));
  char  *sec = xmalloc(10 * sizeof(char));
  char  *hhmmss;

  timestamp = time(NULL);
  tm = localtime(&timestamp);
  snprintf(hour, 10, "%02d", tm->tm_hour);
  snprintf(min, 10, "%02d", tm->tm_min);
  snprintf(sec, 10, "%02d", tm->tm_sec);
  hhmmss = xmalloc((strlen(hour) + strlen(min) + strlen(sec) + 3)
		   * sizeof(char));
  strcat(hhmmss, hour);
  strcat(hhmmss, ":");
  strcat(hhmmss, min);
  strcat(hhmmss, ":");
  strcat(hhmmss, sec);
  free(hour);
  free(min);
  free(sec);
  return (hhmmss);
}

char    *date_system()
{
  time_t timestamp;
  struct tm * tm;
  char  *year = xmalloc(10 * sizeof(char));
  char  *month = xmalloc(10 * sizeof(char));
  char  *day = xmalloc(10 * sizeof(char));
  char  *yymmdd;

  timestamp = time(NULL);
  tm = localtime(&timestamp);
  snprintf(year, 10, "%d", tm->tm_year + 1900);
  snprintf(month, 10, "%02d", tm->tm_mon + 1);
  snprintf(day, 10, "%02d", tm->tm_mday);
  yymmdd = xmalloc((strlen(year) + strlen(month) + strlen(day) + 3)
		   * sizeof(char));
  strcat(yymmdd, year);
  strcat(yymmdd, "-");
  strcat(yymmdd, month);
  strcat(yymmdd, "-");
  strcat(yymmdd, day);
  free(year);
  free(month);
  free(day);
  return (yymmdd);
}
