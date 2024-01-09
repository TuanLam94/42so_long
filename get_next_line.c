/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:50:03 by tlam              #+#    #+#             */
/*   Updated: 2023/11/23 13:50:36 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

int	found_newline(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_to_stash(int fd, char *stash)
{
	int		readbyte;
	char	*buf;

	readbyte = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!found_newline(stash) && readbyte > 0)
	{
		readbyte = read(fd, buf, BUFFER_SIZE);
		if ((stash == NULL && readbyte == 0) || readbyte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readbyte] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_strdup_to_newline(stash);
	stash = clean_stash(stash);
	return (line);
}

/*
int main()
{
	int fd;
	int fd2;
	char	*line;
	char	*line2;

	fd = open("tests/andthat", O_RDONLY);
	fd2 = open("tests/trythis", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break;
		free(line);
		line2 = get_next_line(fd2);
		printf("%s\n", line2);
		if (line2 == NULL)
			break;
		free(line2);
	}
	
	return (0);
}
*/