/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:45:30 by swedde            #+#    #+#             */
/*   Updated: 2019/10/07 17:03:16 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sw_print_grid(char **grid, int i)
{
	int n;
	int m;

	n = 0;
	while (n <= i)
	{
		m = 0;
		while (m <= i)
		{
			write(1, &grid[n][m], 1);
			m++;
		}
		write(1, "\n", 1);
		n++;
	}
}

char	**sw_increase_grid(int *i)
{
	char	**grid;
	int		y;
	int		l;

	(*i)++;
	if (!(grid = (char **)malloc(sizeof(char *) * (*i + 2))))
		return (NULL);
	y = 0;
	while (y < *i + 1)
	{
		if (!(grid[y] = (char *)malloc(sizeof(char) * (*i + 2))))
			return (NULL);
		grid[y][*i + 1] = '\0';
		y++;
	}
	grid[*i + 1] = 0;
	y = 0;
	while (y < *i + 1)
	{
		l = 0;
		while (l < *i + 1)
			grid[y][l++] = '.';
		y++;
	}
	return (grid);
}

void	sw_del_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	free(grid);
	grid = NULL;
}
