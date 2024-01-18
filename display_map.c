/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:31:37 by tlam              #+#    #+#             */
/*   Updated: 2024/01/10 17:31:38 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_img_init(t_data *data)
{
	int		img_width;
	int		img_height;
	t_img	assets;

	assets.character = mlx_xpm_file_to_image
		(data->mlx_ptr, CHARACTER_PATH, &img_width, &img_height);
	assets.wall = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL_PATH, &img_width, &img_height);
	assets.terrain = mlx_xpm_file_to_image
		(data->mlx_ptr, TERRAIN_PATH, &img_width, &img_height);
	assets.collectible = mlx_xpm_file_to_image
		(data->mlx_ptr, COLLECTIBLE_PATH, &img_width, &img_height);
	assets.exit = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_PATH, &img_width, &img_height);
	assets.skeleton = mlx_xpm_file_to_image
		(data->mlx_ptr, SKELETON_PATH, &img_width, &img_height);
	return (assets);
}

void	sprite_to_window(t_data data, void *asset, int j, int i)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, asset, j * 50, i * 50);
}

void	ft_put_to_window(t_data data, t_img assets)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
				sprite_to_window(data, assets.wall, j, i);
			else if (data.map[i][j] == '0')
				sprite_to_window(data, assets.terrain, j, i);
			else if (data.map[i][j] == 'P')
				sprite_to_window(data, assets.character, j, i);
			else if (data.map[i][j] == 'C')
				sprite_to_window(data, assets.collectible, j, i);
			else if (data.map[i][j] == 'E')
				sprite_to_window(data, assets.exit, j, i);
			else if (data.map[i][j] == 'S')
				sprite_to_window(data, assets.skeleton, j, i);
			j++;
		}
		i++;
	}
}

t_point	get_player_position(t_data data)
{
	t_point	begin;
	int		i;
	int		j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == 'P')
			{
				begin.x = j;
				begin.y = i;
			}
			j++;
		}
		i++;
	}
	return (begin);
}
