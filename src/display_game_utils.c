/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:19:57 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 19:44:01 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_path_to_image(char c)
{
	if (c == '0')
		return ("./images/grass.xpm");
	else if (c == '1')
		return ("./images/wall.xpm");
	else if (c == 'P')
		return ("./images/hero.xpm");
	else if (c == 'C')
		return ("./images/flowers.xpm");
	else
		return ("./images/exit.xpm");
}

void	display_line(char **s, void *mlx_ptr, void *win_ptr, int y)
{
	int		x;
	int		width;
	int		height;
	void	*img_ptr;
	char	*path;

	width = 16;
	height = 16;
	x = 0;
	while ((*s)[x])
	{
		path = get_path_to_image((*s)[x]);
		img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 32 * x, 32 * y);
		x++;
	}
}
