/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:18:55 by rklein            #+#    #+#             */
/*   Updated: 2019/11/22 10:22:55 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(char **board, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			write(1, &board[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		ft_sqrt(int nb)
{
	float temp;
	float sqrt;

	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	return ((int)sqrt);
}

int		ft_col_max(t_tetro **pieces, int i)
{
	int j;
	int max;

	max = pieces[i]->cell[0]->col;
	j = 1;
	while (j < 4)
	{
		if (pieces[i]->cell[j]->col > max)
			max = pieces[i]->cell[j]->col;
		j++;
	}
	return (max);
}

int		ft_row_max(t_tetro **pieces, int i)
{
	int j;
	int max;

	max = pieces[i]->cell[0]->row;
	j = 1;
	while (j < 4)
	{
		if (pieces[i]->cell[j]->row > max)
			max = pieces[i]->cell[j]->row;
		j++;
	}
	return (max);
}

int		ft_col_min(t_tetro **pieces, int i)
{
	int j;
	int min;

	min = pieces[i]->cell[0]->col;
	j = 1;
	while (j < 4)
	{
		if (pieces[i]->cell[j]->col < min)
			min = pieces[i]->cell[j]->col;
		j++;
	}
	return (min);
}
