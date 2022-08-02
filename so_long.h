/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:46:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 15:39:36 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "libs/minilibx/mlx.h"
# include "libs/libft/libft.h"

# define TRUE 1
# define FALSE 0

# define SPRITE 32
# define MLX_ERROR 1

typedef struct s_window
{
    void    *win_ptr;
    int     width;
    int     height;
}   t_window;

typedef struct s_game
{
    void        *mlx_ptr;
    t_window    window;
    char        **map;
}   t_game;

char        **generate_map(char *path);
int         num_rows(char **tab);
void        free_tab(char **tab);
int         is_equal_colum_size(char **map);
int         is_valid_wall(char **map);
int         is_valid_map(char **map);
int         get_qtd_character(char **map, char character);
t_window    get_window_size(char **map);
void        init_window(t_game game);
#endif