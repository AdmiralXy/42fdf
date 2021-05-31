#include "ft_fdf.h"

void	ft_set_pixel(t_point point, int color, t_fdf *data)
{
	if (!data->mlx)
		ft_exit(data);
	mlx_pixel_put(data->mlx, data->mlx_win, point.x, point.y, color);
}

t_point	ft_set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

int 	ft_get_height_color(t_point p1, t_point p2, t_fdf *data)
{
	int	z1;
	int	z2;

	z1 = data->map[p1.y][p1.x];
	z2 = data->map[p2.y][p2.x];
	if (z1 || z2)
		return (0xff0000);
	return (0xffffff);
}

void	ft_bresenham(t_point p1, t_point p2, t_fdf *data)
{
	int	deltaX;
	int	deltaY;
	int	error;
	int	error_check;
	int	color;

	color = ft_get_height_color(p1, p2, data);
	ft_transforms(&p1, &p2, data);
	deltaX = ft_abs(p2.x - p1.x);
	deltaY = ft_abs(p2.y - p1.y);
	error = deltaX - deltaY;
	ft_set_pixel(p1, color, data);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		ft_set_pixel(p1, color, data);
		error_check = error * 2;
		if (error_check > -deltaY)
		{
			error -= deltaY;
			p1.x += ft_nbrcmp(p2.x, p1.x);
		}
		if (error_check < deltaX)
		{
			error += deltaX;
			p1.y += ft_nbrcmp(p2.y, p1.y);
		}
	}
}

void	ft_draw(t_fdf *data, int clear)
{
	int		x;
	int		y;

	if (clear)
		mlx_clear_window(data->mlx, data->mlx_win);
	ft_render_text(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(ft_set_point(x, y), ft_set_point(x + 1, y), data);
			if (y < data->height - 1)
				ft_bresenham(ft_set_point(x, y), ft_set_point(x, y + 1), data);
			x++;
		}
		y++;
	}
}
