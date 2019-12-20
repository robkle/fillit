/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:00:48 by rklein            #+#    #+#             */
/*   Updated: 2019/12/12 12:23:39 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_makecell(t_tetro **pieces, char *str, int i, int *j)
{
	int k;
	int	xy[2];

	k = -1;
	while (++k < 4)
	{
		while (str[++(*j)] != '#')
			;
		if (k == 0)
		{
			xy[0] = (*j - i) % 5;
			xy[1] = (*j - i) / 5;
		}
		pieces[i]->cell[k] = malloc(sizeof(t_coord));
		pieces[i]->cell[k]->col = ((*j - i) % 5) - xy[0];
		pieces[i]->cell[k]->row = ((*j - i) / 5) - xy[1];
	}
}

static void	ft_boardcell(t_tetro **pieces, int i)
{
	int	j;

	j = -1;
	while (++j < 4)
	{
		pieces[i]->board_coord[j] = malloc(sizeof(t_coord));
		pieces[i]->board_coord[j]->col = 0;
		pieces[i]->board_coord[j]->row = 0;
	}
}

void		ft_makestruct(t_tetro **pieces, char *str, int size)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		pieces[i] = malloc(sizeof(t_tetro));
		pieces[i]->id = i;
		pieces[i]->nb_tetro = size;
		ft_makecell(pieces, str, i, &j);
		ft_boardcell(pieces, i);
		pieces[i]->min_col = -ft_col_min(pieces, i);
		pieces[i]->max_col = ft_col_max(pieces, i);
		pieces[i]->max_row = ft_row_max(pieces, i);
	}
}
