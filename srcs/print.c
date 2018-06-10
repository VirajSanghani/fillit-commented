/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:24:28 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/09 16:07:34 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**put_piece(char *array, int count, int i, int j)
{
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * count + 1)))
	
	count = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] != '\n')
			map[j][count++] = array[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	change_letter(char **tet, int i, int j)
{
	char	c;
	c = 'A';
	while (tet[i] != '\0')
	{
		while(tet[i][j] != '\0')
		{
			if (tet[i][j] == '#')
				tet[i][j] = c;
			j++;
		}
		j = 0;
		c++;
		i++;
	}
	if (c > 'Z' + 1)
		error();
}

void	print(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putendl(str[i]);
		i++;
	}
}
