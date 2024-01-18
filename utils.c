/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:14:35 by tlam              #+#    #+#             */
/*   Updated: 2024/01/09 16:14:37 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strduplicate(const char *s)
{
	int		i;
	char	*dest;
	int		len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_arraylen(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	**create_new_map(t_data data)
{
	char	**dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	dest = malloc(sizeof(char *) * (data.row + 1));
	if (!dest)
		return (NULL);
	while (i < data.row)
	{
		dest[i] = ft_strdup(data.map[i]);
		if (!dest[i])
		{
			while (j < i)
			{
				free(dest[j++]);
			}
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
