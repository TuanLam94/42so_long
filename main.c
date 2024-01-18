/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:14:50 by tlam              #+#    #+#             */
/*   Updated: 2024/01/08 16:14:51 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_assets(t_data data)
{
	if ((open(CHARACTER_PATH, O_RDONLY) == -1)
		|| (open(WALL_PATH, O_RDONLY) == -1)
		|| (open(TERRAIN_PATH, O_RDONLY) == -1)
		|| (open(COLLECTIBLE_PATH, O_RDONLY) == -1)
		|| (open(EXIT_PATH, O_RDONLY) == -1)
		|| (open(SKELETON_PATH, O_RDONLY) == -1))
	{
		invalid_map(data, -1);
		return (0);
	}
	return (1);
}

void	launch_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "So Long");
	data->assets = ft_img_init(data);
	ft_put_to_window(*data, data->assets);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &keycheck, data);
	mlx_hook(data->win_ptr, DESTROY_NOTIF, NO_EVENT_NASK, &escape, data);
	mlx_loop(data->mlx_ptr);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->col = 0;
	data->row = 0;
	data->fd = 0;
	data->map = NULL;
	data->collectibles = 0;
	data->exit = 0;
	data->character = 0;
	data->moves = 0;
	data->mapname = ft_strdup("map/map1.ber");
}

int	main(void)
{
	t_data	data;

	init_data(&data);
	if (!check_assets(data))
		return (0);
	if (!check_map(&data))
		return (0);
	launch_game(&data);
	endgame(&data, &data.assets, 1);
	return (0);
}
