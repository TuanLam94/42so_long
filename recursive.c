/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:57 by tlam              #+#    #+#             */
/*   Updated: 2024/01/11 12:54:58 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_doable(t_data data)
{
	char	**map;
	int		exit;
	int		collect;
	t_point	cur;

	collect = 0;
	cur = get_player_position(data);
	map = create_new_map(data);
	exit = fill_exit(map, data.size, cur);
	free_tab(map);
	map = create_new_map(data);
	fill_collect(map, data.size, cur, &collect);
	free_tab(map);
	if (!exit || collect < data.collectibles)
		return (0);
	return (1);
}

static int	stop_tile_collect(char c)
{
	if (c == 'C' || c == 'P' || c == '0')
		return (0);
	return (1);
}

static int	stop_tile_exit(char c)
{
	if (c == 'C' || c == 'P' || c == '0' || c == 'E')
		return (0);
	return (1);
}

void	fill_collect(char **map, t_point size, t_point cur, int *collect)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| stop_tile_collect(map[cur.y][cur.x]))
		return ;
	if (map[cur.y][cur.x] == 'C')
		(*collect)++;
	map[cur.y][cur.x] = 'D';
	fill_collect(map, size, (t_point){cur.x - 1, cur.y}, collect);
	fill_collect(map, size, (t_point){cur.x + 1, cur.y}, collect);
	fill_collect(map, size, (t_point){cur.x, cur.y - 1}, collect);
	fill_collect(map, size, (t_point){cur.x, cur.y + 1}, collect);
}

int	fill_exit(char **map, t_point size, t_point cur)
{
	int	left;
	int	right;
	int	down;
	int	up;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| stop_tile_exit(map[cur.y][cur.x]))
		return (0);
	if (map[cur.y][cur.x] == 'E')
		return (1);
	map[cur.y][cur.x] = 'D';
	left = fill_exit(map, size, (t_point){cur.x - 1, cur.y});
	right = fill_exit(map, size, (t_point){cur.x + 1, cur.y});
	down = fill_exit(map, size, (t_point){cur.x, cur.y - 1});
	up = fill_exit(map, size, (t_point){cur.x, cur.y + 1});
	return (left || right || down || up);
}
