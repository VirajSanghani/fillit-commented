/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:24:28 by vsanghan          #+#    #+#             */
/*   Updated: 2018/06/11 18:00:37 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	put_letter(char **tet, int i, int j)
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

void	print(char **str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putendl(str[i]);
		i++;
	}
}

int			count_tet(char *s)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}
