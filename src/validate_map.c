/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:06:25 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/22 19:50:45 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_borders_valid(t_so_long **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0' && (*data)->map[y][x] != '\n')
		{
			if (y == 0 || y == (*data)->height - 1)
				if ((*data)->map[y][x] != '1')
					return (1);
			if (x == 0 || x == (*data)->width - 2)
				if ((*data)->map[y][x] != '1')
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	exists_character(t_so_long **data, char c)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	exists_invalid_character(t_so_long **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if (!((*data)->map[y][x] == 'E' || (*data)->map[y][x] == 'C' ||
				(*data)->map[y][x] == 'P' || (*data)->map[y][x] == '1' ||
				(*data)->map[y][x] == ' '))
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_rectangular(t_so_long **data, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
			x++;
		if (x != width)
			return (1);
		y++;
	}
	if (y != height)
		return (1);
	return (width == height);
}

int	is_map_valid(t_so_long **data)
{
	if (are_borders_valid(data))
		(*data)->message = "Error\nBorders of the map are not valid";
	if (exists_character(data, 'E'))
		(*data)->message = "Error\nEscape is missing in the map";
	if (exists_character(data, 'C'))
		(*data)->message = "Error\nCoins are missing in the map";
	if (exists_character(data, 'P'))
		(*data)->message = "Error\nStarting position is missing in the map";
	if (exists_invalid_character(data))
		(*data)->message = "Error\nThere are invalid characters in the map";
	if (is_rectangular(data, (*data)->width - 1, (*data)->height))
		(*data)->message = "Error\nMap is not a rectangular";
	if ((*data)->message)
		return (0);
	return (1);
}
