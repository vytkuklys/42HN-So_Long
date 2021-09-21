/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:06:38 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 20:07:13 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../gnl/get_next_line.h"

void	free_array(char ***arr)
{
	int		i;
	char	**tmp;

	tmp = *arr;
	if (tmp == NULL)
		return ;
	i = 0;
	while (tmp != NULL && tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	arr = NULL;
}

void	handle_allocation_error(t_so_long **data)
{
	(*data)->message = "Error\nOn Memory Allocation";
	exit_game(data, 0);
}

int	exit_game(t_so_long **data, int flag)
{
	if ((*data)->message)
		write(1, (*data)->message, ft_strlen((*data)->message));
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	free_array(&(*data)->map);
	free(*data);
	*data = NULL;
	if (flag)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
	return (0);
}
