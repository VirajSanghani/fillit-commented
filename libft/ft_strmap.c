/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:49:13 by ncosta            #+#    #+#             */
/*   Updated: 2018/05/03 19:43:37 by ncosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	size_t			i;
	size_t			siz;
	char			*newstr;

	if (!s || !f)
		return (0);
	siz = ft_strlen(s);
	newstr = ft_strnew(siz);
	if (!newstr)
		return (0);
	i = -1;
	while (++i < siz)
		newstr[i] = f(s[i]);
	return (newstr);
}
