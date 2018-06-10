/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 06:58:07 by ncosta            #+#    #+#             */
/*   Updated: 2018/06/09 16:06:56 by vsanghan         ###   ########.fr       */
/*   Updated: 2018/05/31 14:12:15 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

#define BUF_SIZE 547

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	
	if (argc != 2)
	{
		ft_putstr("usage: fillit [file]\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (fd != 3 || ret > 521 || ret < 20)
	{
		ft_putstr("error: not a valid file\n");
		return (1);
	}	
	if (!checker(buf))
	{
		ft_putstr("error: not a valid tetrimino\n");
		return (1);
	}
	funtion_caller(tet, count, buf, fd);
	return (0);
}
