/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:46:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/03 14:46:46 by sjhony-x         ###   ########.fr       */
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
# define PATH_IMG_SPACE "assets/images/space.xpm"
# define PATH_IMG_WALL "assets/images/wall.xpm"
# define PATH_IMG_TUX_RIGHT "assets/images/tux_right.xpm"
# define PATH_IMG_COIN_0 "assets/images/coin_0.xpm"
# define PATH_IMG_EXIT "assets/images/exit.xpm"

# define KEY_ESC	0xff1b
# define KEY_LEFT	0xff51
# define KEY_UP		0xff52  
# define KEY_RIGHT	0xff53
# define KEY_DOWN	0xff54
# define KEY_A		0x0041
# define KEY_S		0x0053
# define KEY_D		0x0044
# define KEY_W		0x0057

typedef struct s_image
{
	void	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_game
{
	void		*mlx_ptr;
	char		**map;
	t_window	window;
	t_image		wall;
	t_image		space;
	t_image		tux_right;
	t_image		coin_0;
	t_image		exit;
}	t_game;

char		**generate_map(char *path);
int			num_rows(char **tab);
void		free_tab(char **tab);
int			is_equal_colum_size(char **map);
int			is_valid_wall(char **map);
int			is_valid_map(char **map);
int			get_qtd_character(char **map, char character);
t_window	get_window_size(char **map);
void		init_window(t_game *game);
void		load_images(t_game *game);
void		draw_image(t_game *game, t_image *img);

//renders
int			render_map(t_game *game);

#endif