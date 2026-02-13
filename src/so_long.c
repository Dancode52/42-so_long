/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/13 16:05:31 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	error_function(int error);

void	error_function(int error)
{
	if (error == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Malloc error\n", 13);
		exit(EXIT_FAILURE);
	}
	if (error == -2)
	{
		write(2, "Error\n", 6);
		write(2, "Invalid number of args or no .ber file.\n", 40);
		write(2, "Valid input is './so_long path/to/map.ber'.\n", 44);
		exit(EXIT_FAILURE);
	}
	if (error == -3)
	{
		write(2, "Error\n", 6);
		write(2, "Map invalid. A line of the given map is too long.\n", 54);
		write(2, "Make sure all lines are of equal length \n", 41);
		exit(EXIT_FAILURE);
	}
}

void	map_path_check(char *mappath)
{
	int	i = ft_strlen(mappath);
	int j = 0;
	char *str;

	if (!mappath)
		return (0);
	i = ft_strlen(mappath);
	j = 0;
	str = ".ber";
	if (i <= 4)
		return (0);
	while (j < 4)
	{
		if (mappath[i - 1] == str[3 - j])
			printf("%i letters match\n", j);
		else
		{
			exitfunctionforerrors;
			return (0);
		}
		j++;
		i--;
	}
	return (1);
}

char *load_map_to_string(char *map_path, int fd)
{
	int		readchars;
	char	*buf;
	char	*tmp;
	char	*res;
	int		fd;

	if (!map_path)
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	readchars = 1;
	res = NULL;
	while (readchars > 0)
	{
		readchars = read(fd, buf, BUFFER_SIZE);
		if (readchars < 0)
			functiontofreeifthingsbreak;
		buf[readchars] = '\0';
    	tmp = ft_strjoin(res, buf);
    	free(res);
    	res = tmp;
	}
	close(fd);
	free(buf);
	return (res);
}

int	map_parse(char *map_path)
{
	char	*mapstr;
	char	**map;
	int		fd;
	size_t	pathlen;

//---- check if map path is valid
	map_path_check(map_path);
//---- load map to string
	mapstr = load_map_to_string(map_path);
//---- load map to array
	map = load_map_to_array(map_path);
//---- check if map is playable
	flood_fill_map(map);
//---- profit
	pathlen = ft_strlen(map_path);
	if (!map_path || pathlen <= 4 || !is_ber(map_path))//!ft_strncmp(map_path + pathlen - 4, ".ber", 4))
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	mapstr = get_map(map_path, fd);
	map = ft_split(mapstr, '\n');
	free(mapstr);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		error_function(-2);
	i = map_parse(argv[1]);
	if (i < 0)
		return (0);
	printf("It worked! i = %d. GG!\n", i);
}
