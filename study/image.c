#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 800
# define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

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
			mlx_put_image_to_window(mlx, win, image->img, x, y);
			x += 64;
		}
		y += 64;
	}
}

int	main(void)
{
	t_data data;
	char	*relative_path = "img/background.xpm";
	int		img_width;
	int		img_height;
	t_image	img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return MLX_ERROR;
	}
	img.img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	render_background(data.mlx_ptr, data.win_ptr, &img);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (0);
}
