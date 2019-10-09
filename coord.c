/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:21:26 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:03:10 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*find_coord(char **newbuf)
{
	int			i;
	int			j;
	int			k;
	int			*coord;

	if (!(coord = (int *)malloc(sizeof(int) * 8)))
		sw_exit();
	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (newbuf[i][j] == '#')
			{
				coord[k] = i;
				coord[k + 1] = j;
				k += 2;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

t_fillit	*newlst(int *a, char c)
{
	t_fillit	*l;

	if (!(l = (t_fillit *)malloc(sizeof(t_fillit))))
		sw_exit();
	l->content = a;
	l->c = c;
	l->next = NULL;
	return (l);
}

void		ft_push_back(t_fillit **start, int *coord, char letter)
{
	t_fillit	*l;

	l = *start;
	if (*start == NULL)
		*start = newlst(coord, letter);
	else
	{
		while (l->next != NULL)
		{
			l = l->next;
		}
		l->next = newlst(coord, letter);
	}
}
