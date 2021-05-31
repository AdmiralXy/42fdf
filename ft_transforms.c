#include "ft_fdf.h"

void	ft_proj(t_point *point, float angle, int z)
{
	point->x = (int)round((point->x - point->y) * cos(angle));
	point->y = (int)round((point->x + point->y) * sin(angle) - z);
}

void	ft_isometric(t_point *point, float angle, int z)
{
	point->x = (int)round((point->x - point->y) * cos(angle));
	point->y = (int)round((point->x + point->y) * sin(angle) - z);
}

void	ft_scale(t_point *p1, t_point *p2, int value)
{
	p1->x *= value;
	p1->y *= value;
	p2->x *= value;
	p2->y *= value;
}

void	ft_shift(t_point *p1, t_point *p2, int x_val, int y_val)
{
	p1->x += x_val;
	p1->y += y_val;
	p2->x += x_val;
	p2->y += y_val;
}

void	ft_transforms(t_point *p1, t_point *p2, t_fdf *data)
{
	int	z1;
	int	z2;
	int	elevate;

	elevate = data->elevate;
	if (!elevate)
		elevate = 1;
	z1 = data->map[p1->y][p1->x] * elevate;
	z2 = data->map[p2->y][p2->x] * elevate;
	ft_scale(p1, p2, data->scale);
	ft_isometric(p1, data->angle, z1);
	ft_isometric(p2, data->angle, z2);
	ft_shift(p1, p2, data->shift_x, data->shift_y);
}
