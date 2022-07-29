#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int	close(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 200, "My Window");
	mlx_hook(vars.win, KeyPress, KeyPressMask, &close, &vars);
	mlx_loop(vars.mlx);
}