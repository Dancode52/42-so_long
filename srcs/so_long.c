/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/10 16:06:37 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/get_next_line_bonus.h"

int	map_parse(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len == 0)
		return (0);
	if (!ft_strnstr(map_path, ".ber", len))
		error_function(-1);
}

void	error_function(int error)
{
	if (error == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Invalid number of args or no .ber file. Valid input is './so_long path/to/map.ber'.", 67);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_function(-1);
}
