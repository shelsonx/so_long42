/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:46:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/07/29 19:46:36 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define FALSE 0
# include <fcntl.h>
# include "libs/libft/libft.h"

char	**generate_map(char *path);
int		num_rows(char **tab);
void	free_tab(char **tab);
int		is_equal_colum_size(char **map);
int		is_valid_wall(char **map);
int		is_valid_map(char **map);
int	get_qtd_character(char **map, char character);
#endif