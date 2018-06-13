/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 06:58:07 by ncosta            #+#    #+#             */
/*   Updated: 2018/06/13 14:13:22 by vsanghan         ###   ########.fr       */
/*   Updated: 2018/05/31 14:12:15 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int 	fd;
	int 	ret;
	int		count;
	char 	*buf;
	char 	**tet;
	
	if (argc != 2)
	{
		ft_putstr("usage: fillit [file]\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	tet = NULL;
	buf = (char*)malloc(BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE + 1);
	buf[ret] = '\0';
	count = count_tet(buf);
	if (checker(buf, count) != 1)
	{
		exit(0);
	}
	f_caller(tet, count, buf, fd);
	return (0);
}
