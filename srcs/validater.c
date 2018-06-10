/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:01:28 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/09 16:34:04 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_in_map(char *array, int count, int i, int j)
{
	char	**matrix;

	if (!(matrix = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	matrix[count] = NULL;
	while (i < count)
	{
		if (!(matrix[i++] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		matrix[i - 1][16] = '\0';
	}
	count = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] != '\n')
			matrix[j][count++] = array[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

char	**remove_piece(char **square, char *str, int i, int j)
{
	char	chr;

	chr = str[how_many_dots(str)];
	while (square[j])
	{
		while (square[j][i])
		{
			if (square[j][i] == chr)
				square[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (square);
}

char	**new_square(int size)
{
	char	**square;
	int		i;
	int		j;

	i = 0;
	if (!(square = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	square[size] = NULL;
	while (i < size)
	{
		if (!(square[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		square[i][size] = '\0';
		i++;
	}
	i = 0;
	while (square[i])
	{
		j = 0;
		while (j < size)
			square[i][j++] = '.';
		i++;
	}
	return (square);
}

char **put_piece()
