/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:01:28 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/11 17:13:09 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_in_map(char *tet, int count, int i, int j)
{
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	map[count] = NULL;
	while (i < count)
	{
		if (!(map[i++] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		map[i - 1][16] = '\0';
	}
	count = 0;
	i = 0;
	while (tet[i] != '\0')
	{
		if (tet[i] != '\n')
			map[j][count++] = tet[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int		validate_piece(char **tetris, int i, int j)
{
	if ((j + 1) >= 0 && tetris[i][j + 1] == '#')
		if (((j + 1) % 4) == 0)
			return (0);
	return (((j - 1) >= 0 && tetris[i][j - 1] == '#')
			+ ((j - 4) >= 0 && tetris[i][j - 4] == '#')
			+ ((j + 1) <= 15 && tetris[i][j + 1] == '#')
			+ ((j + 4) <= 15 && tetris[i][j + 4] == '#'));
}

void	validater(char **tetris, int i, int j, int hash)
{
	int	ok;
	int	center;

	while (tetris[++i] != '\0')
	{
		center = 0;
		while ((tetris[i][++j] != '\0') && (tetris[i][j] == '.' ||
					tetris[i][j] == '\n' || tetris[i][j] == '#'))
			if (tetris[i][j] == '#')
			{
				if ((ok = validate_piece(tetris, i, j)) > 0)
				{
					hash++;
					if (ok > 1)
						center = ok;
				}
				else
					exit(1);
			}
		if (center <= 1 || hash != 4 || tetris[i][j] != '\0')
			exit(1);
		hash = 0;
		j = -1;
	}
}
