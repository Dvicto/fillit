/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_startgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:13:32 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/07 17:03:18 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			lst_size(t_fillit *l)
{
	int i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

int			ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	if (i * i > nb)
		i--;
	return (i);
}

void		ft_lstdel1(t_fillit **alst)
{
	t_fillit	*lst;
	t_fillit	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		free(lst->content);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}

void		start_grid(t_fillit *l)
{
	char		**grid;
	int			i;

	i = ft_sqrt(lst_size(l) * 4) - 2;
	grid = sw_increase_grid(&i);
	while (solve_square(grid, i, l) == 0)
	{
		sw_del_grid(grid);
		grid = sw_increase_grid(&i);
	}
	sw_print_grid(grid, i);
	sw_del_grid(grid);
	ft_lstdel1(&l);
}
