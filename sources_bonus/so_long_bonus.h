/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:46:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/08 14:25:00 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

# define TRUE 1
# define FALSE 0
# define INCREMENT 1
# define DECREMENT 0

# define SPRITE 32
# define PATH_IMG_SPACE "assets/images/space.xpm"
# define PATH_IMG_WALL "assets/images/wall.xpm"
# define PATH_IMG_COIN_0 "assets/images/coin_0.xpm"
# define PATH_IMG_EXIT "assets/images/exit.xpm"
# define PATH_IMG_TUX_RIGHT "assets/images/tux_right.xpm"
# define PATH_IMG_TUX_LEFT "assets/images/tux_left.xpm"
# define PATH_IMG_TUX_UP "assets/images/tux_up.xpm"
# define PATH_IMG_TUX_DOWN "assets/images/tux_down.xpm"
# define PATH_IMG_BACK_MOVE "assets/images/back_move.xpm"
# define PATH_IMG_BOMB "assets/images/bomb.xpm"
# define PATH_IMG_GAME_OVER "assets/images/game_over.xpm"

# define KEY_ESC		0xff1b
# define KEY_LEFT		0xff51
# define KEY_UP			0xff52  
# define KEY_RIGHT		0xff53
# define KEY_DOWN		0xff54
# define KEY_A			0x0061
# define KEY_S			0x0073
# define KEY_D			0x0064
# define KEY_W			0x0077

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

typedef struct s_image_bonus
{
	t_image		back_move;
	t_image		bomb;
	t_image		game_over;
}	t_image_bonus;

typedef struct s_game
{
	void			*mlx_ptr;
	char			**map;
	int				moves;
	int				collectibles;
	int				end_game;
	t_image_bonus	image_bonus;
	t_window		window;
	t_image			wall;
	t_image			space;
	t_image			tux;
	t_image			coin;
	t_image			door;
}	t_game;

//map
char		**generate_map(char *path);
int			is_equal_colum_size(char **map);
int			is_valid_wall(char **map);
int			is_valid_map(char **map);
int			get_qtd_character(char **map, char character);

//map utils
int			num_rows(char **tab);
void		free_tab(char **tab);
t_window	get_window_size(char **map);
int			is_ext_valid(char *filename);

//image utils
void		load_img_pos_tux(t_game *game, char *path);
void		load_images(t_game *game);
void		draw_image(t_game *game, t_image *img);

//renders
int			render_map(t_game *game);

//events
int			events(int key, t_game *game);
void		down(t_game *game);
void		up(t_game *game);
void		right(t_game *game);
void		left(t_game *game);

//events utils
void		swap_play_for_space(t_game *game, char coord, int move);
void		finalize_player(t_game *game);

//game
void		init_game(t_game *game);
int			exit_game(t_game *game);
void		init_window(t_game *game);
void		game_over(t_game *game);

#endif