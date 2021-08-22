/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:52:01 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/22 21:03:59 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	*data;
	char 		*file_name;

	if (argc != 2)
	{
		write(1, "Error\nWrong number of command line arguments", 45);
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	data = get_map_data(file_name);
	if (data == NULL)
	{
		write(1, "Error\nError occurred when opening the file", 42);
		exit(EXIT_FAILURE);
	}
	if (!is_map_valid(&data))
		exit_game(&data, 0);
	display_game(&data);
	return (0);
}
