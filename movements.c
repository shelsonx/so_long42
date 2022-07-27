#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

typedef struct s_image
{
	void	*addr;
	int		x;
	int		y;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	background;
	t_image supertux;
}	t_data;



int	close(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	return (0);
}

void	render_background(void *mlx, void *win, t_image *image)
{
	if (win == NULL)
		return ;
	int x;
	int y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_image_to_window(mlx, win, image->addr, x, y);
			x += 64;
		}
		y += 64;
	}
}


int	key_input(int key, t_data *data)
{
	if (key == XK_Left)
		data->supertux.x -= 20;
	else if (key == XK_Right)
		data->supertux.x += 20;
	else if (key == XK_Down)
		data->supertux.y += 20;
	else if (key == XK_Up)
		data->supertux.y -= 20;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);

	render_background(data->mlx_ptr, data->win_ptr, &data->background);
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr, data->supertux.addr, 
		data->supertux.x, data->supertux.y);
	return (0);
}

int	main(void)
{
	t_data data;
	char	*relative_path = "img/background.xpm";
	char	*supertux_path = "img/supertux.xpm";
	int		stux_width;
	int		stux_height;
	int		img_width;
	int		img_height;

	data.supertux.x = 0;
	data.supertux.y = 0;


	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return MLX_ERROR;
	}
	data.background.addr = mlx_xpm_file_to_image(
		data.mlx_ptr, relative_path, &img_width, &img_height);
	data.supertux.addr = mlx_xpm_file_to_image(data.mlx_ptr, supertux_path, &stux_width, &stux_height);

	mlx_key_hook(data.win_ptr, key_input, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	
	free(data.mlx_ptr);

	return (0);
}
