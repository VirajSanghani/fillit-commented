/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:54:10 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/11 16:41:35 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtrack(char **tet, char **map, int i)
{
	char 	*str;
	int		x;
	int		y;

	if (!tet[i])
		return (1);
	y = 0;
	str = tet[i];
	while (y < count_bits(map))
	{
		x = 0;
		while (x < count_bits(map))
		{
			if (check_map(map, str, x, y) == 1)
			{
				map = put_piece(map, str, x, y);
				if (backtrack(tet, map, i + 1) == 1)
					return (1);
				remove_piece(map, str, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**remove_piece(char **map, char *letter, int i, int j)
{
	char  piece_to_remove;

	piece_to_remove = letter[num_dots(letter)];
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == piece_to_remove)
				map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (map);
}

char	**put_piece(char **square, char *str, int i, int j)
{
	int		k;
	int		dots;

	dots = num_dots(str);
	k = dots - 1;
	while (str[++k])
	{
		if (str[k] != '.')
			square[j + (k / 4) - (dots / 4)][i + (k % 4) - (dots % 4)] = str[k];
	}
	return (square);
}

int		count_bits(char **str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		num_dots(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}
