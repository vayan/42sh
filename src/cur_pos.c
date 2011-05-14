/*
** cur_pos.c for  in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Thu May 12 14:20:09 2011 timothee maurin
** Last update Fri May 13 17:15:43 2011 timothee maurin
*/

int	cur_pos(char *buf, int i)
{
  int	p;
  int	tmp;
  int	ret;

  ret = 2;
  p = 0;
  while (p < i)
    {
      if (buf[p] == 9)
	{
	  tmp = ret % nbr_column();
	  tmp = tmp % 8;
	  if (ret % nbr_column() + 8 - tmp < nbr_column())
	    ret += 8 - tmp;
	  else
	    ret += nbr_column() - ret % nbr_column();
	}
      else
	ret++;
      p++;
    }
  return (ret);
}
