/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:30:38 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/16 22:10:38 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./gnl/get_next_line.h"
char	*replace_zeroes_with_spaces(char **line)
{
	char	*newline;
	int		i;

	if (*line == NULL)
		return (NULL);
	i = 0;
	newline = (char *)malloc(ft_strlen(*line) * sizeof(char) + 1);
	while (!((*line)[i] == '\0' || (*line)[i] == '\n'))
	{
		if ((*line)[i] == '0')
			newline[i] = ' ';
		else
			newline[i] = (*line)[i];
		i++;
		printf("%c", 'a');
	}
	newline[i] = '\0';
	printf("%s", newline);
	free(*line);
	return (newline);
}

int	display_window(char *file_name, t_so_long *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open(file_name, O_RDONLY);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 900, "Collect pellets");
	line = get_next_line(fd);
	while (line)
	{
		line = replace_zeroes_with_spaces(&line);
		printf("%s", line);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 12 * i, 0xffffff, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	// printf("magic");
	mlx_loop(data->mlx_ptr);
	return (1);
}
