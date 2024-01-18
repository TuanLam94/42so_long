/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:55:50 by tlam              #+#    #+#             */
/*   Updated: 2024/01/11 14:55:53 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	endgame(t_data *data, t_img *assets, int type)
{
	if (type == 0)
		write (2, "Error, invalid map\n", 19);
	else if (type == 1)
		write (1, "Game complete !\n", 16);
	else if (type == 2)
		write (1, "You died !\n", 11);
	mlx_destroy_image(data->mlx_ptr, assets->wall);
	mlx_destroy_image(data->mlx_ptr, assets->character);
	mlx_destroy_image(data->mlx_ptr, assets->collectible);
	mlx_destroy_image(data->mlx_ptr, assets->terrain);
	mlx_destroy_image(data->mlx_ptr, assets->exit);
	mlx_destroy_image(data->mlx_ptr, assets->skeleton);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_tab(data->map);
	free(data->mlx_ptr);
	free(data->mapname);
	exit(0);
}

void	invalid_map(t_data data, int type)
{
	free_tab(data.map);
	free(data.mapname);
	if (type == 0)
		write(2, "Error, invalid map\n", 19);
	if (type == 1)
		write(2, "Error, wrong map format\n", 24);
	if (type == 2)
		write(2, "Error, can't open the map\n", 26);
	if (type == -1)
		write (2, "Error, can't read the assets\n", 30);
	exit(0);
}
