/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:08:36 by tkuumola          #+#    #+#             */
/*   Updated: 2019/11/22 10:13:13 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_tetrino_board_coord(int row, int col, t_tetro **pieces,\
																	int t_nb)
{
	int i;

	i = 0;
	while (i < 4)
	{
		pieces[t_nb]->board_coord[i]->row = pieces[t_nb]->cell[i]->row + row;
		pieces[t_nb]->board_coord[i]->col = pieces[t_nb]->cell[i]->col + col;
		i++;
	}
}

static int	ft_is_fit(t_tetro **pieces, int tetro_nb, char **board)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (board[pieces[tetro_nb]->board_coord[i]->row]\
			[pieces[tetro_nb]->board_coord[i]->col] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_board_update(char **board, t_tetro **pieces, int tetro_nb,\
													char filler)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board[pieces[tetro_nb]->board_coord[i]->row]\
						[pieces[tetro_nb]->board_coord[i]->col] = filler;
		i++;
	}
}

static int	ft_solve_board(char **board, int board_size,\
												t_tetro **pieces, int c)
{
	int		r_c[2];

	if (c >= pieces[0]->nb_tetro)
		return (1);
	r_c[0] = -1;
	while (++r_c[0] < board_size - pieces[c]->max_row)
	{
		r_c[1] = pieces[c]->min_col - 1;
		while (++r_c[1] < board_size - pieces[c]->max_col)
		{
			if (board[r_c[0]][r_c[1]] == '.')
			{
				ft_tetrino_board_coord(r_c[0], r_c[1], pieces, c);
				if (ft_is_fit(pieces, c, board))
				{
					ft_board_update(board, pieces, c, (pieces[c]->id + 'A'));
					if (ft_solve_board(board, board_size, pieces, (c + 1)))
						return (1);
					else
						ft_board_update(board, pieces, c, '.');
				}
			}
		}
	}
	return (0);
}

char		**ft_solve(t_tetro **pieces)
{
	char	**board;
	int		board_size;

	board_size = ft_sqrt(pieces[0]->nb_tetro * 4);
	if (!(board = ft_dynamic_array_alloc(board_size, board_size)))
		exit(0);
	while (!(ft_solve_board(board, board_size, pieces, 0)))
	{
		ft_free_array(board, board_size);
		board_size++;
		if (!(board = ft_dynamic_array_alloc(board_size, board_size)))
			exit(0);
	}
	ft_print_board(board, board_size);
	ft_free_array(board, board_size);
	return (board);
}
