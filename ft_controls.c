#include "ft_fdf.h"

int	ft_controls_system(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_EXIT && ++finded)
		ft_exit(data);
	return (finded);
}

int	ft_controls_transforms(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_SCALE_PLUS && ++finded)
		data->scale++;
	if (keycode == KEY_SCALE_MINUS && ++finded)
		data->scale--;
	if (keycode == KEY_ROTATE_LEFT && ++finded)
		data->angle += M_PI / 16;
	if (keycode == KEY_ROTATE_RIGHT && ++finded)
		data->angle -= M_PI / 16;
	if (keycode == KEY_HEIGHT_PLUS && ++finded)
		data->elevate++;
	if (keycode == KEY_HEIGHT_MINUS && ++finded)
		data->elevate--;
	return (finded);
}

int	ft_controls_move(int keycode, t_fdf *data)
{
	int	finded;

	finded = 0;
	if (keycode == KEY_UP && ++finded)
		data->shift_y -= 50;
	if (keycode == KEY_DOWN && ++finded)
		data->shift_y += 50;
	if (keycode == KEY_RIGHT && ++finded)
		data->shift_x += 50;
	if (keycode == KEY_LEFT && ++finded)
		data->shift_x -= 50;
	return (finded);
}

int	ft_controls(int keycode, t_fdf *data)
{
	int	finded;

	finded = ft_controls_system(keycode, data);
	finded |= ft_controls_transforms(keycode, data);
	finded |= ft_controls_move(keycode, data);
	return (finded);
}
