/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:46:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/10 17:39:11 by sjhony-x         ###   ########.fr       */
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
# define SPEED_ANIMATION 2000
# define PATH_IMG_SPACE 		"assets/images/space.xpm"
# define PATH_IMG_WALL 			"assets/images/wall.xpm"
# define PATH_IMG_COIN_0 		"assets/images/coin_0.xpm"
# define PATH_IMG_EXIT 			"assets/images/exit.xpm"
# define PATH_IMG_TUX_RIGHT 	"assets/images/tux_right.xpm"
# define PATH_IMG_TUX_LEFT 		"assets/images/tux_left.xpm"
# define PATH_IMG_TUX_UP 		"assets/images/tux_up.xpm"
# define PATH_IMG_TUX_DOWN 		"assets/images/tux_down.xpm"

//path images bonus
# define PATH_IMG_BACK_MOVE 	"assets/images/back_move.xpm"
# define PATH_IMG_FLY 			"assets/images/fly.xpm"
# define PATH_IMG_FLY_1 		"assets/images/fly_1.xpm"
# define PATH_IMG_FLY_2 		"assets/images/fly_2.xpm"
# define PATH_IMG_FLY_3 		"assets/images/fly_3.xpm"
# define PATH_IMG_FLY_5 		"assets/images/fly_5.xpm"
# define PATH_IMG_COIN_1 		"assets/images/coin_1.xpm"
# define PATH_IMG_COIN_2 		"assets/images/coin_2.xpm"
# define PATH_IMG_COIN_3		"assets/images/coin_3.xpm"
# define PATH_IMG_COIN_4 		"assets/images/coin_4.xpm"
# define PATH_IMG_COIN_5 		"assets/images/coin_5.xpm"
# define PATH_IMG_COIN_6 		"assets/images/coin_6.xpm"
# define PATH_IMG_COIN_7 		"assets/images/coin_7.xpm"
# define PATH_IMG_GAME_OVER 	"assets/images/game_over.xpm"

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
	t_image		fly;
	t_image		game_over;
}	t_image_bonus;

typedef struct s_game
{
	void			*mlx_ptr;
	char			**map;
	int				moves;
	int				collectibles;
	int				end_game;
	int				count_animations;
	int				frame;
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
void		render(t_game *game, t_image *image, int x, int y);
void		render_default_map(t_game *game);
void		render_moves(t_game *game);
void		render_enemy(t_game *game);

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

//bonus animation
int			animation(t_game *game);

//bonus animation utils
void		swap_fly(t_game *game, char *path);
void		swap_coin(t_game *game, char *path);
void		update_frame(t_game *game);
int			swap_coins(t_game *game, int frame);
int			swap_flies(t_game *game, int frame);

#endif