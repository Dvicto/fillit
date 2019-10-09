/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_and_mv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:28:07 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:09:33 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***full_check(char *buffer, int numtet)
{
	char	***newbuf;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (!(buffer = check2(buffer)))
		ex_fr_buf(&buffer);
	if (!(buffer = check3(buffer, j, i, k)))
		ex_fr_buf(&buffer);
	i = 0;
	k = 0;
	j = 0;
	newbuf = buf2d(buffer, i, j, k);
	free(buffer);
	if (!((check4(newbuf, numtet, i, j))))
		ex_fr_newbuf(&newbuf, numtet);
	return (newbuf);
}

char		***full_move(char ***newbuf, int numtet)
{
	int		k;
	int		n;

	k = 0;
	n = 0;
	if (!(newbuf = search_left_figure(newbuf, numtet)))
	{
		free(newbuf);
		return (NULL);
	}
	if (!(newbuf = search_up_figure(newbuf, numtet, k, n)))
	{
		free(newbuf);
		return (NULL);
	}
	return (newbuf);
}

void		frnewbuf(char ****newbuf, int numtet)
{
	int		i;
	int		n;

	i = 0;
	while (i < numtet)
	{
		n = 0;
		while (n < 4)
		{
			free((*newbuf)[i][n]);
			(*newbuf)[i][n] = NULL;
			n++;
		}
		free((*newbuf)[i]);
		i++;
	}
	free(*newbuf);
}

t_fillit	*figure(char ****newbuf, int numtet)
{
	t_fillit	*abc;
	int			**a;
	int			z;
	char		b;

	abc = NULL;
	b = 'A';
	z = 0;
	if (!(a = (int **)malloc(sizeof(int *) * numtet)))
		sw_exit();
	while (z < numtet)
	{
		a[z] = find_coord((*newbuf)[z]);
		z++;
	}
	z = 0;
	while (z < numtet)
	{
		ft_push_back(&abc, a[z], b++);
		z++;
	}
	frnewbuf(newbuf, numtet);
	z = 0;
	free(a);
	return (abc);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		***newbuf;
	char		*buffer;
	int			numtet;
	t_fillit	*abc;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!(buffer = check1(fd)))
	{
		free(buffer);
		return (0);
	}
	numtet = (ft_strlen(buffer) + 1) / 21;
	if (!(newbuf = full_check(buffer, numtet)))
		return (0);
	if (!(newbuf = full_move(newbuf, numtet)))
		return (0);
	abc = figure(&newbuf, numtet);
	start_grid(abc);
	return (1);
}
