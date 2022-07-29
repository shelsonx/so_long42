#include <mlx.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 300
# define RED 0xFF0000

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

void my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*offset;
	offset = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)offset = color;
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
			my_put_pixel(data, i, j++, color);
		i++;
	}
}

int	render(t_data *data, void *mlx, void *win)
{
	render_background(data, RED);
	mlx_put_image_to_window(mlx, win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	void	*mlx;
	void	*win;
	t_data img;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 300, "My Window");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_loop_hook(mlx, &render, &img);
	
	mlx_loop(mlx);
}
