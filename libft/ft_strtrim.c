/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:02:07 by ncosta            #+#    #+#             */
/*   Updated: 2018/05/03 20:08:33 by ncosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_special_whitespace(const char c)
{
	if (c != '\0' && (c == ' ' || c == '\n' || c == '\t'))
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	size_t				len;
	size_t				begin;
	int					end;

	if (!s)
		return (0);
	len = ft_strlen(s);
	end = len - 1;
	begin = -1;
	while (is_special_whitespace(s[++begin]) && begin < len)
		;
	while (is_special_whitespace(s[end--]) && end > -1)
		;
	if (end == -1 || begin >= len)
		return (ft_strnew(1));
	else
	{
		len = ++end - begin + 1;
		return (ft_strsub(s, begin, len));
	}
}
