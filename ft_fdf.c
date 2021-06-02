#include "ft_fdf.h"

int	ft_key_mlx(int keycode, t_fdf *data)
{
	int	finded;

	printf("Key pressed: %d\n", keycode);
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
	if (!ft_parser("/home/kricky/CLionProjects/fdf/test_maps/42.fdf", data))
	{
		free(data);
		return (0);
	}
	if (!ft_init_fdf(data))
		return (0);
	ft_draw(data, 0);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_key_hook(data->mlx_win, ft_key_mlx, data);
	mlx_loop(data->mlx);
	return (0);
}
