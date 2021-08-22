/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:08:05 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/22 20:10:03 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../gnl/get_next_line.h"

int	get_perimeter(char *file_name, t_so_long **data)
{
	char	*line;
    int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	(*data)->width = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*data)->height++;
	}
	close(fd);
	return (0);
}

void	add_longitude_data(char **map, char *line)
{
	char	*tmp;
	int		j;

	tmp = *map;
	j = 0;
	while (line != NULL && line[j] != '\0' && line[j] != '\n')
	{
		if (line[j] == '0')
			tmp[j] = ' ';
		else
			tmp[j] = line[j];
		j++;
	}
	tmp[j] = '\0';
}

int	read_line(char *file_name, t_so_long **data)
{
	char	*line;
	int		i;
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	(*data)->map = (char **)malloc(((*data)->height + 1) * sizeof(char *));
	if ((*data)->map == NULL)
		handle_allocation_error(data);
	i = 0;
	line = NULL;
	while (i < (*data)->height)
	{
		line = get_next_line(fd);
		(*data)->map[i] = (char *)malloc(((*data)->width));
		if ((*data)->map[i] == NULL)
			handle_allocation_error(data);
		add_longitude_data(&(*data)->map[i], line);
		free(line);
		i++;
	}
	(*data)->map[i] = NULL;
	return (0);
}

void	get_player_pos(t_so_long **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'P')
			{
				(*data)->player_x = x;
				(*data)->player_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

t_so_long	*get_map_data(char *file_name)
{
	t_so_long	*data;
	data = (t_so_long *)malloc(sizeof(t_so_long));
	ft_initialise_data(&data);
	if (get_perimeter(file_name, &data) || read_line(file_name, &data))
	{
		free(data);
		return (NULL);
	}
	get_player_pos(&data);
	return (data);
}
