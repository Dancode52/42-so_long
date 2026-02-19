/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:52:33 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/19 14:04:45 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_path_check(char *map_path)
{
	int	mappathlen;
	int berlen;
	char *berfile;

	berfile = ".ber";
	if (!map_path)
	{
		ft_putstr_fd("Error\nHow did this happen?\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strrchr(map_path, '/'))
		map_path = ft_strrchr(map_path, '/') + 1;
	mappathlen = ft_strlen(map_path);
	berlen = ft_strlen(berfile);
	if (mappathlen <= 4)
	{
		ft_putstr_fd("Error\nFile names must have at least 5 characters\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(map_path + mappathlen - berlen, berfile, berlen))
	{
		ft_putstr_fd("Error\nMap must be a .ber file\n", 2);
		exit(EXIT_FAILURE);
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
	{
		ft_printf("Error\nMap doesn't exist: %s\n", strerror(2));
		exit(EXIT_FAILURE);
	}
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
	{
		ft_printf("Error\nMalloc break in load_map_to_string\n");
		exit(EXIT_FAILURE);
	}
	res = make_string_from_file(buf, fd);
	close(fd);
	free(buf);
	ft_printf("res = %s\n", res);
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
	return (res);
}

char **load_map_to_array(char *mapstr)
{
	char	**maparray;

	if (!mapstr)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		exit(EXIT_FAILURE);
	}
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
