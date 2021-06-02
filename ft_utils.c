#include "ft_fdf.h"

int	**ft_calloc_2d(int n_rows, int n_cols)
{
	int	**p;
	int	i;

	i = 0;
	p = ft_calloc(n_rows, sizeof(int *));
	if (!p)
		return (0);
	while (i < n_rows)
	{
		p[i] = ft_calloc(n_cols, sizeof(int));
		if (!p[i])
		{
			return (0);
		}
		i++;
	}
	return (p);
}

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

int	ft_init_fdf(t_fdf *data)
{
	data->proj = 1;
	data->scale = 22;
	data->angle = M_PI / 3;
	data->shift_x = WIN_HEIGHT / 3;
	data->shift_y = WIN_WIDTH / 3;
	data->shift_z = 1;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->mlx_win = mlx_new_window(data->mlx, WIN_HEIGHT, WIN_WIDTH, "42FDF");
	if (!data->mlx_win)
		return (0);
	return (1);
}

int	ft_get_height_color(t_point *p1, t_point *p2, t_fdf *data)
{
	int	z1;
	int	z2;

	z1 = data->map[p1->y][p1->x];
	z2 = data->map[p2->y][p2->x];
	if (z1 || z2)
		return (0xff0000);
	return (0xffffff);
}

void	ft_exit(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_clear_map(data->map, data);
	free(data);
	exit(0);
}
