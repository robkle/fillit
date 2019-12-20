/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:55:10 by rklein            #+#    #+#             */
/*   Updated: 2019/11/22 11:14:50 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

static char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	d = (char*)malloc(sizeof(*d) * (ft_strlen((char*)s1)
				+ ft_strlen((char*)s2) + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (*s1)
	{
		d[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		d[i] = *s2;
		i++;
		s2++;
	}
	d[i] = '\0';
	return (d);
}

static int		ft_return(char **str, int rv, int count)
{
	if (rv < -1)
		return (-1);
	if (!*str)
		return (0);
	if ((*str)[ft_strlen(*str) - 1] == '\n' &&
	(*str)[ft_strlen(*str) - 2] == '\n')
		return (0);
	return (count);
}

int				ft_read(int fd, char **str)
{
	int		rv;
	char	buffer[22];
	char	*tmp;
	int		count;

	count = 0;
	while ((rv = read(fd, buffer, 21)) > 0)
	{
		buffer[rv] = '\0';
		if (ft_checkfile(buffer, rv) != 1)
			return (0);
		count++;
		if (*str == NULL)
			*str = ft_strnew(0);
		tmp = ft_strjoin(*str, buffer);
		free(*str);
		*str = tmp;
	}
	return (ft_return(str, rv, count));
}
