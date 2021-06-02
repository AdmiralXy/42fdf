#include "ft_fdf.h"

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
	ft_putstr_mlx("F/G - Shift Heights", 0, data);
	ft_putstr_mlx("ESC - Exit", 0, data);
}
