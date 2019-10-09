/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:17:53 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/07 17:11:40 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include "./libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_fillit
{
	int				*content;
	struct s_fillit	*next;
	char			c;
}					t_fillit;

void				start_grid(t_fillit *l);
int					solve_square(char **grid, int i, t_fillit *tet);
void				sw_print_grid(char **grid, int i);
char				**sw_increase_grid(int *i);
void				sw_del_grid(char **grid);
char				*check1(const int fd);
char				*check2(char *buf);
char				*check3(char *buf, int i, int j, int k);
char				***buf2d(const char *buf, int n, int k, int m);
int					check4(char ***newbuf, int numtet, int n, int m);
char				**make_up_fugure(char **newbuf, int i, int k);
char				***search_up_figure(char ***newbuf, int numtet,
					int k, int n);
char				**make_left_figure(char **newbuf, int i, int n, int k);
char				***search_left_figure(char ***newbuf, int numtet);
char				***full_check(char *buffer, int numtet);
char				***full_move(char ***newbuf, int numtet);
t_fillit			*newlst(int *a, char c);
int					*find_coord(char **newbuf);
void				ft_push_back(t_fillit **start, int *coord, char letter);
t_fillit			*figure(char ****newbuf, int numtet);
int					checkkk4(char	**newbuf, int i, int n, int m);
int					check_search_up(char *newbuf);
void				ex_fr_newbuf(char ****newbuf, int numtet);
void				ex_fr_buf(char **buf);
void				frnewbuf(char ****newbuf, int numtet);
int					sw_chxy(t_point **e, int i);
void				sw_exit(void);

#endif
