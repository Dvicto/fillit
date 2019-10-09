/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:58:23 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/07 17:03:17 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_safe(char **grid, int i, t_point *e, int *content)
{
	int j;

	j = 0;
	while (j < 8)
		if (e->x + content[j + 1] <= i && e->y + content[j] <= i && grid[e->y +
		content[j]][e->x + content[j + 1]] == '.')
			j += 2;
		else
			return (0);
	return (1);
}

int		find_unassigned_location(char **grid, int i, t_point **e, int *content)
{
	while ((*e)->y <= i)
	{
		while ((*e)->x <= i)
		{
			if (is_safe(grid, i, *e, content))
				return (1);
			(*e)->x++;
		}
		(*e)->y = -~(*e)->y;
		(*e)->x = 0;
	}
	return (0);
}

void	sw_insert(char **grid, t_point *e, int *content, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		grid[e->y + content[i]][e->x + content[i + 1]] = c;
		i += 2;
	}
}

void	sw_delete(char **grid, t_point *e, int *content)
{
	int i;

	i = 0;
	while (i < 8)
	{
		grid[e->y + content[i]][e->x + content[i + 1]] = '.';
		i += 2;
	}
}

int		solve_square(char **grid, int i, t_fillit *tet)
{
	t_point *e;

	if (!tet)
		return (1);
	if (!(e = (t_point *)malloc(sizeof(t_point))))
		sw_exit();
	e->x = 0;
	e->y = 0;
	while (find_unassigned_location(grid, i, &e, tet->content))
	{
		sw_insert(grid, e, tet->content, tet->c);
		if (solve_square(grid, i, tet->next))
		{
			free(e);
			return (1);
		}
		sw_delete(grid, e, tet->content);
		if (sw_chxy(&e, i))
		{
			free(e);
			return (0);
		}
	}
	free(e);
	return (0);
}
