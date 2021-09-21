/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:56:05 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 19:41:59 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_screen(t_so_long **data)
{
	char	*header;

	header = "...San Francisco, be sure to wear some flowers in your hair";
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr,
			((*data)->width - 1) * 32, (*data)->height * 32, header);
}

void	ft_initialize_data(t_so_long **data)
{
	(*data)->player_y = 0;
	(*data)->player_x = 0;
	(*data)->counter = 0;
	(*data)->height = 0;
	(*data)->width = 0;
	(*data)->mlx_ptr = NULL;
	(*data)->win_ptr = NULL;
	(*data)->message = NULL;
	(*data)->map = NULL;
}
