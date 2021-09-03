/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:44 by                   #+#    #+#             */
/*   Updated: 2021/09/04 01:20:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_get_max_height(t_fdf *data)
{
	int	i;
	int	j;
	int	max;

	max = -2147483648;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] > max)
				max = data->map[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

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

void	ft_clear_map(int **map, t_fdf *data)
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
	data->scale = (int) rintf(55 / rintf((float) data->width / 10));
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

void	ft_exit(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_clear_map(data->map, data);
	free(data);
	exit(0);
}
