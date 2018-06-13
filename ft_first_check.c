/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:30:21 by ncosta            #+#    #+#             */
/*   Updated: 2018/06/13 14:13:55 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  ft_check_symbol(char *s)
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

int		ft_check_line(char *s)
{
	int x;
	int y;
	int add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

int		ft_check_piece(char *s)
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

int			checker(char *tab, int count)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (i < count)
	{
		if (ft_check_symbol(&tab[i]) != 1)
			return (0);
		if (ft_check_line(&tab[i]) != 1)
			return (0);
		if (ft_check_piece(&tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
