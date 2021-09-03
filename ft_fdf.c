/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricky <kricky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:13:21 by                   #+#    #+#             */
/*   Updated: 2021/09/04 01:17:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_key_mlx(int keycode, t_fdf *data)
{
	int	key_exists;

	ft_putstr_fd("Key pressed: ", 1);
	ft_putnbr_fd(keycode, 1);
	ft_putendl_fd("", 1);
	key_exists = ft_controls(keycode, data);
	if (key_exists)
		ft_draw(data, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_putendl_fd("Please specify the path to the map!", 1);
		return (1);
	}
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (1);
	if (!ft_parser(argv[1], data) || !ft_init_fdf(data))
	{
		ft_putendl_fd("Map not found or has invalid format!", 1);
		free(data);
		return (1);
	}
	ft_draw(data, 0);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_key_hook(data->mlx_win, ft_key_mlx, data);
	mlx_loop(data->mlx);
	return (0);
}
