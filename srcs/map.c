/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:08:04 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/06 06:12:20 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	fillit(char **map, int nb)
{
	char	**str;
	int		size;

	size = ft_sqrt(nb * 4);
	str = new_square(size);
	while (backtrack(map, str, 0) == 0)
	{
		size++;
		free_map(str);
		str = new_square(size);
	}
	aff_matrix(str);
}

int		ft_sqrt(int len)
{
	int i;

	i = 2;
	while (i * i < len)
		i++;
	return (i);
}

char 	**new_square(int size)
{
	char 	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
			return (0);
	map[size] = '\0';
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
			map[i][j++] + '.';
		i++;
	}
	return (map);

void	free_map(char **map)
{
	int i;
	int j;

	i = ft_strlen(map);
	j = 0;
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
