/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:50 by tlam              #+#    #+#             */
/*   Updated: 2024/01/17 16:09:52 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_square(t_data data)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (data.map[i] && data.map[i + 1])
	{
		a = ft_strlen(data.map[i]);
		b = ft_strlen(data.map[i + 1]);
		if (a == b)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_map_ruled(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles += 1;
			else if (data->map[i][j] == 'E')
				data->exit += 1;
			else if (data->map[i][j] == 'P')
				data->character += 1;
			j++;
		}
		i++;
	}
	if (data->collectibles >= 1 && data->exit == 1 && data->character == 1)
		return (1);
	else
		return (0);
}

int	is_map_surrounded_by_walls(t_data data)
{
	int	i;
	int	len;
	int	lastrow;

	i = 0;
	len = ft_strlen(data.map[i]) - 1;
	lastrow = ft_arraylen(data.map) - 1;
	while (data.map[0][i])
	{
		if (data.map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while (data.map[lastrow][i])
	{
		if (data.map[lastrow][i++] != '1')
			return (0);
	}
	i = 0;
	while (data.map[i])
	{
		if (data.map[i][0] != '1' || data.map[i++][len] != '1')
			return (0);
	}
	return (1);
}

static int	is_content(char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != 'S')
		return (0);
	else
		return (1);
}

int	check_map_content(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (!is_content(data.map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
