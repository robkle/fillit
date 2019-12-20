/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:51:08 by rklein            #+#    #+#             */
/*   Updated: 2019/11/20 17:03:10 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_neighbour(char *str, int i)
{
	int	c;
	int	n[4];
	int j;

	n[0] = i - 5;
	n[1] = i - 1;
	n[2] = i + 1;
	n[3] = i + 5;
	c = 0;
	j = -1;
	while (++j < 4)
	{
		if (n[j] >= 0 && n[j] < 20 && str[n[j]] == '#')
			c++;
	}
	return (c);
}

static int	ft_checktetro(char *str)
{
	int	i;
	int c;
	int m;
	int	t;

	i = -1;
	c = 0;
	m = 0;
	t = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			t++;
			c = ft_neighbour(str, i);
			if (c == 0)
				return (0);
			if (c > m)
				m = c;
		}
	}
	return (t == 4 && m > 1 ? 1 : 0);
}

int			ft_checkfile(char *str, int rv)
{
	int	i;

	if (rv < 20)
		return (0);
	if ((rv == 21 && str[20] != '\n') || (rv == 20 && str[20] != '\0'))
		return (0);
	i = 0;
	while (str[i] && i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (i % 5 < 4 && (str[i] != '.' && str[i] != '#'))
			return (0);
		i++;
	}
	return (ft_checktetro(str));
}
