/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:36:27 by rklein            #+#    #+#             */
/*   Updated: 2019/11/22 11:11:43 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		count;
	t_tetro	*pieces[26];

	if (argc == 2)
	{
		str = NULL;
		if ((fd = open(argv[1], O_RDWR)) < 0)
			return (-1);
		count = ft_read(fd, &str);
		if (count > 0 && count < 27)
		{
			ft_makestruct(pieces, str, count);
			ft_solve(pieces);
			ft_strdel(&str);
			ft_free(pieces, count);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage: ./fillit input_file\n", 28);
	return (0);
}
