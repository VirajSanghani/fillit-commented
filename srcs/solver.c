/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:54:10 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/05 22:56:43 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtrack(char **tet, char **map, int i)
{
	char 	*str;
	int		x;
	int		y;

	if (!tetris[i])
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
				map = next_piece(map, str, x, y);
				if (backtrack(tet, map, i + 1) == 1)
					return (1);
				remove_piece(map, str, 0, 0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		tet_begin(char *str)
{
	int i;

	i = 0;
	while (str[i] != '#')
		i++;
	return (i);
}

char	remove_piece(char **map, char letter, int i, int j)
{
	char  **piece_to_remove;

	piece_to_remove = map;
	while(piece_to_remove[i])
	{
		while(piece_to_remove[j] == letter)
		{
			piece_to_remove[i][j] = '.';
			i++;
		}
		j++;
	}
	return (piece_to_remove);
}

int		count_bits(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
