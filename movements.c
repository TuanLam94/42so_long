/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:34:28 by tlam              #+#    #+#             */
/*   Updated: 2024/01/12 13:34:31 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data, t_img *assets)
{
	t_point	cur;

	cur = get_player_position(*data);
	if (data->map[cur.y][cur.x - 1] == '1'
		|| (data->map[cur.y][cur.x - 1] == 'E' && data->collectibles != 0))
		return ;
	else
	{
		print_moves(data);
		if (data->map[cur.y][cur.x - 1] == 'E' && data->collectibles == 0)
			endgame(data, assets, 1);
		else if (data->map[cur.y][cur.x - 1] == 'S')
			endgame(data, assets, 2);
		else
		{
			if (data->map[cur.y][cur.x - 1] == 'C')
				data->collectibles--;
			data->map[cur.y][cur.x - 1] = 'P';
			data->map[cur.y][cur.x] = '0';
		}
		ft_put_to_window(*data, *assets);
	}
}

void	move_right(t_data *data, t_img *assets)
{
	t_point	cur;

	cur = get_player_position(*data);
	if (data->map[cur.y][cur.x + 1] == '1'
		|| (data->map[cur.y][cur.x + 1] == 'E' && data->collectibles != 0))
		return ;
	else
	{
		print_moves(data);
		if (data->map[cur.y][cur.x + 1] == 'E' && data->collectibles == 0)
			endgame(data, assets, 1);
		else if (data->map[cur.y][cur.x + 1] == 'S')
			endgame(data, assets, 2);
		else
		{
			if (data->map[cur.y][cur.x + 1] == 'C')
				data->collectibles--;
			data->map[cur.y][cur.x + 1] = 'P';
			data->map[cur.y][cur.x] = '0';
		}
		ft_put_to_window(*data, *assets);
	}
}

void	move_up(t_data *data, t_img *assets)
{
	t_point	cur;

	cur = get_player_position(*data);
	if (data->map[cur.y - 1][cur.x] == '1'
		|| (data->map[cur.y - 1][cur.x] == 'E' && data->collectibles != 0))
		return ;
	else
	{
		print_moves(data);
		if (data->map[cur.y - 1][cur.x] == 'E' && data->collectibles == 0)
			endgame(data, assets, 1);
		else if (data->map[cur.y - 1][cur.x] == 'S')
			endgame(data, assets, 2);
		else
		{
			if (data->map[cur.y - 1][cur.x] == 'C')
				data->collectibles--;
			data->map[cur.y - 1][cur.x] = 'P';
			data->map[cur.y][cur.x] = '0';
		}
		ft_put_to_window(*data, *assets);
	}
}

void	move_down(t_data *data, t_img *assets)
{
	t_point	cur;

	cur = get_player_position(*data);
	if (data->map[cur.y + 1][cur.x] == '1'
		|| (data->map[cur.y + 1][cur.x] == 'E' && data->collectibles != 0))
		return ;
	else
	{
		print_moves(data);
		if (data->map[cur.y + 1][cur.x] == 'E' && data->collectibles == 0)
			endgame(data, assets, 1);
		else if (data->map[cur.y + 1][cur.x] == 'S')
			endgame(data, assets, 2);
		else
		{
			if (data->map[cur.y + 1][cur.x] == 'C')
				data->collectibles--;
			data->map[cur.y + 1][cur.x] = 'P';
			data->map[cur.y][cur.x] = '0';
		}
		ft_put_to_window(*data, *assets);
	}
}

void	print_moves(t_data *data)
{
	data->moves += 1;
	ft_printf("Movements : %d\n", data->moves);
}
