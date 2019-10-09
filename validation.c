/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:28:29 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:16:59 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*check1(const int fd)
{
	char	*buf;
	int		reed;
	int		i;

	if (!(buf = (char *)ft_memalloc(BUFF_SIZE)))
		sw_exit();
	i = 0;
	if (!(reed = read(fd, buf, BUFF_SIZE)) || reed > 545)
		ex_fr_buf(&buf);
	buf[reed] = '\0';
	if ((reed != 20) && ((reed - 20) % 21 != 0))
	{
		ex_fr_buf(&buf);
	}
	while (buf[i] != '\0')
	{
		if (buf[i] == '#' || buf[i] == '.' || buf[i] == '\n')
			i++;
		else
			ex_fr_buf(&buf);
	}
	return (buf);
}

char		*check2(char *buf)
{
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\0')
	{
		j = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			i++;
			j++;
		}
		i++;
		if (j != 4 && j != 0)
			ex_fr_buf(&buf);
	}
	if (j != 4)
		ex_fr_buf(&buf);
	return (buf);
}

char		*check3(char *buf, int i, int j, int k)
{
	i = 0;
	while (buf[i] != '\0')
	{
		j = 0;
		k = 0;
		while (j < 4)
		{
			while (buf[i] != '\n' && buf[i] != '\0')
			{
				if (buf[i] == '#')
					k++;
				i++;
			}
			if (buf[i] != '\0')
				i++;
			j++;
		}
		if (buf[i] == '\n')
			i++;
		if (k != 4)
			return (NULL);
	}
	return (buf);
}

char		***buf2d(const char *buf, int n, int k, int m)
{
	char	***newbuf;

	k = 0;
	newbuf = (char ***)malloc(sizeof(char **) * ((ft_strlen(buf) + 1) / 21));
	while (*buf != '\0')
	{
		n = 0;
		if (!(newbuf[k] = (char **)malloc(sizeof(char *) * 4)))
			sw_exit();
		while (n < 4)
		{
			m = 0;
			if (!(newbuf[k][n] = (char *)malloc(sizeof(char) * 4)))
				sw_exit();
			while (m < 4)
				newbuf[k][n][m++] = *buf++;
			buf++;
			n++;
		}
		if (*buf == '\0')
			break ;
		buf++;
		k++;
	}
	return (newbuf);
}

int			check4(char ***newbuf, int numtet, int n, int m)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (k < numtet)
	{
		if (!(checkkk4(newbuf[k], i, n, m)))
			return (0);
		k++;
	}
	return (1);
}
