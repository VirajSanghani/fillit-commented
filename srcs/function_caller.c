/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_caller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:43:28 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/11 17:19:33 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	f_caller(char **tet, int counter, char *buf, int fd)
{
	tet = put_in_map(buf, count, 0, 0);
	free(buf);
	validater(tet, -1, -1, 0);
	put_letter(tet, 0, 0);
	fillit(tet, count);
	close(fd);
}

void	fillit(char **tet, int nb)
{
	char	**map;
	int		size;

	size = ft_sqrt(nb * 4);
	map = new_square(size);
	while (backtrack(tet, map, 0) == 0)
	{
		size++;
		free_square(map);
		map = new_square(size);
	}
	ft_print(map);
}

int		ft_sqrt(int len)
{
	int i;

	i = 2;
	while (i * i < len)
		i++;
	return (i);
}
