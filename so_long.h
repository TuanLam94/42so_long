/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:16:39 by tlam              #+#    #+#             */
/*   Updated: 2024/01/08 16:36:39 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048

# endif

# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

# define CHARACTER_PATH "assets/character.xpm"
# define WALL_PATH "assets/wall.xpm"
# define TERRAIN_PATH "assets/terrain.xpm"
# define EXIT_PATH "assets/exit.xpm"
# define COLLECTIBLE_PATH "assets/collectible.xpm"
# define SKELETON_PATH "assets/skeleton.xpm"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define KEY_RELEASE 3
# define DESTROY_NOTIF 17
# define EXPOSE 12

# define KEY_RELEASE_MASK (1L<<0)
# define EXPOSURE_MASK 32768
# define NO_EVENT_NASK (0L)

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*character;
	void	*wall;
	void	*terrain;
	void	*collectible;
	void	*exit;
	void	*skeleton;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		col;
	int		row;
	int		fd;
	char	**map;
	int		collectibles;
	int		exit;
	int		character;
	int		moves;
	char	*mapname;
	t_point	begin;
	t_point	size;
	t_img	assets;
}	t_data;

void	launch_game(t_data *data);
void	init_data(t_data *data);
int		check_assets(t_data data);

int		check_map(t_data *data);
int		map_is_ber(t_data *data);
int		map_is_valid(t_data *data);
void	get_row_col_size(t_data *data);
char	**get_map(t_data *data);

int		is_map_square(t_data data);
int		is_map_ruled(t_data *data);
int		is_map_surrounded_by_walls(t_data data);
int		check_map_content(t_data data);

void	free_tab(char **map);
void	endgame(t_data *data, t_img *assets, int type);
void	invalid_map(t_data data, int type);

t_img	ft_img_init(t_data *data);
void	sprite_to_window(t_data data, void *asset, int i, int j);
void	ft_put_to_window(t_data data, t_img assets);
t_point	get_player_position(t_data data);

int		keycheck(int keycode, t_data *data);
int		escape(t_data *data);
int		refresh_map(t_data data);

void	move_left(t_data *data, t_img *assets);
void	move_up(t_data *data, t_img *assets);
void	move_down(t_data *data, t_img *assets);
void	move_right(t_data *data, t_img *assets);
void	print_moves(t_data *data);

char	*ft_strduplicate(const char *s);
int		ft_arraylen(char **array);
char	**create_new_map(t_data data);

int		is_map_doable(t_data data);
void	fill_collect(char **map, t_point size, t_point cur, int *collect);
int		fill_exit(char **map, t_point size, t_point cur);

char	*clean_stash(char *stash);
int		found_newline(char *stash);
char	*read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strdup_to_newline(char *src);

int		ft_printf(const char *format, ...);

#endif
