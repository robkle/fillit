/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:22:50 by tkuumola          #+#    #+#             */
/*   Updated: 2019/11/22 11:12:53 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_coord
{
	int	row;
	int	col;
}				t_coord;

typedef struct	s_tetros
{
	int		nb_tetro;
	int		id;
	int		min_col;
	int		max_col;
	int		max_row;
	t_coord	*cell[4];
	t_coord	*board_coord[4];
}				t_tetro;

int				ft_read(int fd, char **str);
int				ft_checkfile(char *str, int rv);
void			ft_makestruct(t_tetro **pieces, char *str, int size);
void			ft_free(t_tetro **pieces, int count);
char			**ft_dynamic_array_alloc(int row, int col);
int				ft_sqrt(int nb);
char			**ft_solve(t_tetro **pieces);
void			ft_print_board(char **board, int size);
void			ft_free_array(char **board, int board_size);
int				ft_col_min(t_tetro **pieces, int i);
int				ft_row_max(t_tetro **pieces, int i);
int				ft_col_max(t_tetro **pieces, int i);
void			ft_strdel(char **as);

#endif
