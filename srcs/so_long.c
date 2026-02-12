/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/12 18:41:07 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	error_function(int error);

int	map_parse(char *map_path)
{
	static size_t	len;
	int				fd;
	char			*maplines;
	size_t			templen;
	int				flag;

	len = ft_strlen(map_path);
	if (len == 0)
		return (0);
	if (!ft_strnstr(map_path, ".ber", len))
		error_function(-2);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	flag = 1;
	while (fd)
	{
		maplines = get_next_line(fd);
		if (!maplines)
		{
			free(maplines);
			maplines = NULL;
			break ;
		}
		if (!len)
			len = ft_strlen(maplines);
		templen = ft_strlen(maplines);
		if (len != templen)
			flag = -1;
		free(maplines);
	}
	close(fd);
	return (flag);
}

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
