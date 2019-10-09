/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validbleat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:24:28 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:11:31 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkkk4(char **newbuf, int i, int n, int m)
{
	i = 0;
	n = 0;
	while (n < 4)
	{
		m = 0;
		while (m < 4)
		{
			if (n - 1 >= 0 && newbuf[n][m] == '#' && newbuf[n - 1][m] == '#')
				i++;
			if (n + 1 < 4 && newbuf[n][m] == '#' && newbuf[n + 1][m] == '#')
				i++;
			if (m - 1 >= 0 && newbuf[n][m] == '#' && newbuf[n][m - 1] == '#')
				i++;
			if (m + 1 < 4 && newbuf[n][m] == '#' && newbuf[n][m + 1] == '#')
				i++;
			m++;
		}
		n++;
	}
	if (i != 6 && i != 8)
		return (0);
	return (1);
}

void	ex_fr_buf(char **buf)
{
	write(1, "error\n", 6);
	free(*buf);
	exit(0);
}

void	ex_fr_newbuf(char ****newbuf, int numtet)
{
	write(1, "error\n", 6);
	frnewbuf(newbuf, numtet);
	exit(0);
}
