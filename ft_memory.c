/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:03:41 by rklein            #+#    #+#             */
/*   Updated: 2019/11/22 11:12:27 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

char	**ft_dynamic_array_alloc(int row, int col)
{
	int		i;
	int		j;
	char	**arr;

	arr = NULL;
	if (!(arr = (char **)malloc(sizeof(char *) * (row))))
		exit(0);
	i = 0;
	while (i < row)
	{
		if (!(arr[i] = (char *)malloc(sizeof(char) * (col))))
		{
			ft_strdel(arr);
			exit(0);
		}
		j = 0;
		while (j < col)
		{
			arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (arr);
}

void	ft_free(t_tetro **pieces, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < 4)
		{
			free(pieces[i]->cell[j]);
			pieces[i]->cell[j] = NULL;
			free(pieces[i]->board_coord[j]);
			pieces[i]->board_coord[j] = NULL;
		}
		free(pieces[i]);
		pieces[i] = NULL;
	}
}

void	ft_free_array(char **board, int board_size)
{
	int i;

	i = 0;
	while (i < board_size)
	{
		ft_strdel(&board[i]);
		i++;
	}
	free(board);
	board = NULL;
}
