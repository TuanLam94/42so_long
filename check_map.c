/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:09:48 by tlam              #+#    #+#             */
/*   Updated: 2024/01/09 16:09:50 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_data *data)
{
	int	tempfd;

	if (!map_is_ber(data))
	{
		invalid_map(*data, 1);
		return (0);
	}
	tempfd = open(data->mapname, O_RDONLY);
	if (tempfd == -1)
	{
		invalid_map(*data, 2);
		return (0);
	}
	close(tempfd);
	if (!map_is_valid(data))
	{
		invalid_map(*data, 0);
		return (0);
	}
	return (1);
}

int	map_is_ber(t_data *data)
{
	int	i;

	i = 0;
	while (data->mapname[i])
		i++;
	i--;
	while (data->mapname[i] != '.')
		i--;
	if (data->mapname[i + 1] == 'b' && data->mapname[i + 2] == 'e'
		&& data->mapname[i + 3] == 'r')
		return (1);
	return (0);
}

int	map_is_valid(t_data *data)
{
	get_row_col_size(data);
	data->map = get_map(data);
	if (is_map_square(*data) && is_map_ruled(data)
		&& is_map_surrounded_by_walls(*data) && is_map_doable(*data)
		&& check_map_content(*data))
		return (1);
	else
		return (0);
}

void	get_row_col_size(t_data *data)
{
	char	*line;
	int		row;
	int		col;

	col = 0;
	row = 0;
	data->fd = open(data->mapname, O_RDONLY);
	if (data->fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break ;
		col = ft_strlen(line);
		row++;
		free(line);
	}
	data->col = col;
	data->row = row;
	data->size.x = col;
	data->size.y = row;
	close(data->fd);
}

char	**get_map(t_data *data)
{
	char	*line;
	int		i;
	char	**dest;

	data->fd = open(data->mapname, O_RDONLY);
	if (data->fd == -1)
		return (NULL);
	dest = malloc(sizeof(char *) * (data->row + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break ;
		dest[i] = ft_strduplicate(line);
		if (!dest[i])
			return (NULL);
		i++;
		free (line);
	}
	dest[i] = NULL;
	return (dest);
}
