/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/12 11:47:10 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkmap(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("%s", "Error\nInvalid file"));
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		map->width = ft_strlen(line) - 1;
		if (map->width == 0)
		{
			free(line);
			return (ft_printf("%s", "Error\nInvalid map"));
		}
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
			{
				free(line);
				return (ft_printf("%s", "Error\nInvalid object in map"));
			}
			i++;
		}
		map->height++;
		free(line);
	}
	close(fd);
	return (0);
}