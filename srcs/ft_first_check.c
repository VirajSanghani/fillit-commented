/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:30:21 by ncosta            #+#    #+#             */
/*   Updated: 2018/06/09 17:28:21 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  ft_check_symbol(char *str)
{
	int i;
	int hash;
	int point;
	int newline;

	i = 0;
	hash = 0;
	point = 0;
	newline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			newline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || newline != 4)
		return (0);
	return (1);
}

int			check_size(char *buf, int size)
{
	int			squ_x;
	int			squ_y;

	while (size >= 0)
	{
		size--;
		squ_y = 0;
		while (squ_y < 4)
		{
			squ_x = 0;
			if (buf[size] != '\n')
				return (0);
			while (squ_x < 4)
			{
				size--;
				if (size < 0 || buf[size] == '\n')
					return (0);
				squ_x++;
			}
			squ_y++;
			size--;
		}
	}
	return (1);
}

static	int		check_tet(char *s)
{
	int height;
	int width;

	height = get_height(s);
	width = get_width(s);
	if (is_alone(s) == 0)
		return (0);
	if (check_void_int(s) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int			checker(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetrimino)
	{
		if (ft_check_symbol(tab[i]) != 1)
			return (0);
		if (ft_check_size(tab[i]) != 1)
			return (0);
		if (ft_check_tet(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
