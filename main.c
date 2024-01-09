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

// int on_destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	exit(0);
// 	return (0);
// }
 
// int on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

void	get_row_col(t_data *data)
{
	char	*line;
	int		row;
	int		col;

	col = 0;
	row = 0;
	data->fd = open("map/map1.ber", O_RDONLY);
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
	close(data->fd);
}

char	**get_map(t_data *data)
{
	char	*line;
	int		i;
	char	**dest;
	int fd = open("map/map1.ber", O_RDONLY);
	
	dest = malloc(sizeof(char *) * (data->row + 1));
	printf("%d\n", data->fd);
	printf("%d\n", fd);
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
	}
	free (line);
	return (dest);
}

int	main(void)
{
	t_data data;
	data.fd = open("map/map1.ber", O_RDONLY);
	get_row_col(&data);
	data.map = get_map(&data);
	int	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}
	return 0;
	// void	*img;
	// int	img_width;
	// int	img_height;

	// data.mlx_ptr = mlx_init();
	// img = mlx_xpm_file_to_image(data.mlx_ptr, path, &img_width, &img_height);
	// data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Hello world!");
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 100, 100);
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// mlx_loop(data.mlx_ptr);
	// free_tab(data->map);
	

}