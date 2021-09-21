/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:55:52 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 19:00:23 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "../minilibx/mlx.h"

typedef struct s_so_long
{
	int		height;
	int		width;
	int		player_y;
	int		player_x;
	int		counter;
	void	*win_ptr;
	void	*mlx_ptr;
	char	**map;
	char	*message;
}	t_so_long;

t_so_long	*get_map_data(char *file_name);
void		display_game(t_so_long **data);
int			is_map_valid(t_so_long **data);
void		free_array(char ***arr);
int			exit_game(t_so_long **data, int flag);
char		*ft_itoa(int n);
void		ft_initialize_data(t_so_long **data);
int			exists_character(t_so_long **data, char c);
void		handle_allocation_error(t_so_long **data);
void		display_line(char **s, void *mlx_ptr, void *win_ptr, int y);
void		ft_initialize_screen(t_so_long **data);

#endif
