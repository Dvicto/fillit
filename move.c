/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:28:41 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:03:14 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**make_up_figure(char **newbuf, int i, int k)
{
	int		n;
	int		m;

	if (i == 0)
		return (newbuf);
	k = i;
	n = 0;
	while (k < 4)
	{
		m = 0;
		while (m < 4)
		{
			newbuf[n][m] = newbuf[k][m];
			m++;
		}
		k++;
		n++;
	}
	k = 4 - i;
	while (k < 4)
	{
		ft_memset(newbuf[k], '.', 4);
		k++;
	}
	return (newbuf);
}

char		***search_up_figure(char ***newbuf, int numtet, int k, int n)
{
	int		fl;

	while (k < numtet)
	{
		n = 0;
		fl = 0;
		while (n < 4)
		{
			if (!(check_search_up(newbuf[k][n])))
				n++;
			else
				break ;
		}
		newbuf[k] = make_up_figure(newbuf[k], n, n);
		k++;
	}
	return (newbuf);
}

char		**make_left_figure(char **newbuf, int i, int n, int k)
{
	int		m;

	if (i == 0)
		return (newbuf);
	m = 0;
	while (k < 4)
	{
		n = 0;
		while (n < 4)
		{
			newbuf[n][m] = newbuf[n][k];
			n++;
		}
		k++;
		m++;
	}
	k = 4 - i;
	while (k < 4)
	{
		m = 0;
		while (m < 4)
			newbuf[m++][k] = '.';
		k++;
	}
	return (newbuf);
}

char		***search_left_figure(char ***newbuf, int numtet)
{
	int		k;
	int		n;
	int		m;

	k = 0;
	while (k < numtet)
	{
		m = 0;
		while (m < 4)
		{
			n = 0;
			while (n < 4)
			{
				if (newbuf[k][n][m] == '#')
					break ;
				n++;
			}
			if (n != 4 && newbuf[k][n][m] == '#')
				break ;
			m++;
		}
		newbuf[k] = make_left_figure(newbuf[k], m, k, m);
		k++;
	}
	return (newbuf);
}

int			check_search_up(char *newbuf)
{
	int m;

	m = 0;
	while (m < 4)
	{
		if (newbuf[m] == '#')
			return (1);
		m++;
	}
	return (0);
}
