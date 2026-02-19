/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:52:33 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 16:14:48 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_path_check(char *mappath)
{
	int	i = ft_strlen(mappath);
	int j = 0;
	char *str;

	if (!mappath)
		return ;
	i = ft_strlen(mappath);
	j = 0;
	str = ".ber";
	if (i <= 4)
		return ;
	while (j < 4)
	{
		if (mappath[i - 1] == str[3 - j])
			ft_printf("%i letters match\n", j + 1);
		else
		{
			ft_putstr_fd("Error\nMap must be a .ber file", 2);
			exit(EXIT_FAILURE);
		}
		j++;
		i--;
	}
	return ;
}

char *load_map_to_string(char *map_path)
{
	char	*buf;
	char	*res;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (0);
	res = make_string_from_file(buf, fd);
	close(fd);
	free(buf);
	empty_line_check(res);
	return (res);
}

#include <stdio.h>

char *make_string_from_file(char *buf, int fd)
{
	int		readchars;
	char	*res;
	char	*tmp;

	res = NULL;
	readchars = 1;
	while (readchars > 0)
	{
		readchars = read(fd, buf, BUFFER_SIZE);
		if (readchars == 0)
			break ;
		if (readchars < 0)
			{
				free(buf);
				ft_putstr_fd("Error\nRead failure.\n", 2);
				exit(EXIT_FAILURE);
			}
		buf[readchars] = '\0';
    	tmp = ft_strjoin(res, buf);
    	free(res);
    	res = tmp;
	}
	ft_printf("string made was:\n%s", res);
	return (res);
}

char **load_map_to_array(char *mapstr)
{
	char	**maparray;

	if (!mapstr)
		return (NULL);
	maparray = ft_split(mapstr, '\n');
	return (maparray);
}

char **map_loading(char *map_path)
{
	char	*mapstr;
	char	**map;

//---- check if map path is valid
	map_path_check(map_path);
//---- load map to string
	mapstr = load_map_to_string(map_path);
//---- load map to array
	map = load_map_to_array(mapstr);
	free(mapstr);
	return (map);
}
