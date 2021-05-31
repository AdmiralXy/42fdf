#include "ft_fdf.h"

void 	ft_clear_map(int **map, t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_init_fdf(t_fdf *data)
{
	data->elevate = 0;
	data->scale = 22;
	data->angle = M_PI / 3;
	data->shift_x = WIN_HEIGHT / 3;
	data->shift_y = WIN_WIDTH / 3;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_HEIGHT, WIN_WIDTH, "42FDF");
}

void	ft_putstr_mlx(char *str, int start, t_fdf *data)
{
	static int	height;

	if (!height || start)
		height = T_OFFSET;
	height += T_HEIGHT;
	mlx_string_put(data->mlx, data->mlx_win, T_OFFSET, height, T_COLOR, str);
}

void	ft_render_text(t_fdf *data)
{
	ft_putstr_mlx("Controls:", 1, data);
	ft_putstr_mlx("W/A/S/D - Move", 0, data);
	ft_putstr_mlx("Q/E - Rotate", 0, data);
	ft_putstr_mlx("Z/X - Scaling", 0, data);
	ft_putstr_mlx("F/G - Elevate Heights", 0, data);
	ft_putstr_mlx("ESC - Exit", 0, data);
}

void	ft_exit(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_clear_map(data->map, data);
	free(data);
	exit(0);
}
