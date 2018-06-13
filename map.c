/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:08:04 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/12 10:58:53 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 	**new_square(int size)
{
	char 	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
			return (0);
	map[size] = NULL;
	while(i < size)
	{
		if (!(map[i] = malloc(sizeof(char) * (size + 1))))
			return (0);
		map[i][size] = '\0';
		i++;
	}
	while (map[i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}

void	free_square(char **map)
{
	int i;
	int j;

	i = ft_strlen(*map);
	j = 0;
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
