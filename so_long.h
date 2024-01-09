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

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048

# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		col;
	int		row;
	int		fd;
	char	**map;
}	t_data;

typedef struct s_img
{
	void			*img;
	char			*path;
	int				img_width;
	int				img_height;
	struct s_img	*next;
}	t_img;

int		found_newline(char *stash);
char	*clean_stash(char *stash);
char	*read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strdup_to_newline(char *stash);
char	*ft_strduplicate(const char *s);
char	**get_map(t_data *data);

#endif

