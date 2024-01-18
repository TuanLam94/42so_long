/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:53:35 by tlam              #+#    #+#             */
/*   Updated: 2024/01/16 11:53:37 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycheck(int keycode, t_data *data)
{
	if (keycode == ESC)
		endgame(data, &data->assets, 3);
	else if (keycode == W)
		move_up(data, &data->assets);
	else if (keycode == A)
		move_left(data, &data->assets);
	else if (keycode == S)
		move_down(data, &data->assets);
	else if (keycode == D)
		move_right(data, &data->assets);
	return (0);
}

int	escape(t_data *data)
{
	endgame(data, &data->assets, 3);
	return (0);
}

int	refresh_map(t_data data)
{
	ft_put_to_window(data, data.assets);
	return (0);
}
