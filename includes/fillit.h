/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:45:49 by ncosta            #+#    #+#             */
/*   Updated: 2018/06/11 17:46:39 by vsanghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUF_SIZE 547

void			fillit(char **tet, int nb);
char			**put_in_map(char *tet, int count, int i, int j);
void			put_letter(char **tet, int i, int j);
char			**ft_validate(int fd, char **tetris);
int				count_tet(char *s);
int				ft_verificare(char *s, int i, int hash, int dot);
int				ft_checker(char *str);
int				backtrack(char **tet, char **map, int i);
char			**put_piece(char **map, char *letter, int i, int j);
void			print(char **str);
int				validate_tetris(char **tetris, int i, int j);
void			validater(char **tetris, int i, int j, int hash);
int				check_map(char **square, char *str, int i, int j);
char			**remove_piece(char **map, char *letter, int i, int j);
char			**new_square(int size);
int				count_bits(char **str);
int				ft_sqrt(int len);
int				num_dots(char *str);
void			free_map(char **map);
int				is_alone(char *s);
int				check_void_int(char *s);
int				get_height(char *s);
int				get_width(char *s);
int				checker(char **tab);
int				ft_check_piece(char *s);
int				ft_check_line(char *s);
int  			ft_check_symbol(char *s);
void			f_caller(char **tet, int counter, char *buf, int fd);
