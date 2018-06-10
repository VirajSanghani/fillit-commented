/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:42:54 by ncosta            #+#    #+#             */
/*   Updated: 2018/05/10 12:56:08 by ncosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t n)
{
	char *array;
	size_t i;

	array = (char *)str;
	i = 0;
	while (i < n)
	{
		array[i] = (unsigned char)x;
		i++;
	}
	return (str);
}
