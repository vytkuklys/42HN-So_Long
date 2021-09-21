/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:30:38 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 19:44:15 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(char ***s, void *mlx_ptr, void *win_ptr)
{
	char	**tmp;
	int		y;

	tmp = *s;
	y = 0;
	while (tmp[y] != NULL)
	{
		display_line(&tmp[y], mlx_ptr, win_ptr, y);
		y++;
	}
}

void	display_movement_count(t_so_long **data)
{
	char	*num;

	num = ft_itoa((*data)->counter);
	if (num == NULL)
		handle_allocation_error(data);
	mlx_string_put((*data)->mlx_ptr, (*data)->win_ptr,
		12, 16, 0x00000f, num);
	free(num);
}

void	update_map(t_so_long **data, int x, int y)
{
	if ((*data)->map[y][x] != '1' && (*data)->map[y][x] != 'E')
	{
		(*data)->map[(*data)->player_y][(*data)->player_x] = '0';
		(*data)->map[y][x] = 'P';
		(*data)->player_x = x;
		(*data)->player_y = y;
	}
	else if ((*data)->map[y][x] == 'E')
	{
		if (exists_character(data, 'C'))
		{
			(*data)->message = "Good Game!";
			exit_game(data, 1);
		}
	}
	(*data)->counter++;
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	display_map(&(*data)->map, (*data)->mlx_ptr, (*data)->win_ptr);
	display_movement_count(data);
}

int	move_player(int key, t_so_long **data)
{
	if (key == 13)
		update_map(data, (*data)->player_x, (*data)->player_y - 1);
	else if (key == 1)
		update_map(data, (*data)->player_x, (*data)->player_y + 1);
	else if (key == 0)
		update_map(data, (*data)->player_x - 1, (*data)->player_y);
	else if (key == 2)
		update_map(data, (*data)->player_x + 1, (*data)->player_y);
	else if (key == 53)
	{
		(*data)->message = "Game Over!";
		exit_game(data, 1);
	}
	return (0);
}

void	display_game(t_so_long **data)
{
	display_map(&(*data)->map, (*data)->mlx_ptr, (*data)->win_ptr);
	display_movement_count(data);
	mlx_key_hook((*data)->win_ptr, move_player, data);
	mlx_hook((*data)->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_loop((*data)->mlx_ptr);
}
