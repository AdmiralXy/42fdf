#include "ft_fdf.h"

int	ft_key_mlx(int keycode, t_fdf *data)
{
	int	finded;

	finded = ft_controls(keycode, data);
	if (finded)
		ft_draw(data, 1);
	return (0);
}

int	main(void)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	if (!ft_parser("/home/kricky/CLionProjects/fdf/test_maps/mars.fdf", data))
	{
		free(data);
		return (0);
	}
	ft_init_fdf(data);
	ft_draw(data, 0);
	mlx_key_hook(data->mlx_win, ft_key_mlx, data);
	mlx_loop(data->mlx);
	return (0);
}
