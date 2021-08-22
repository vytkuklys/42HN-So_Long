/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:26 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/22 17:10:59 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialise_data(t_so_long **data)
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
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr,
			1000, 900, "Collect Coins to Win the Game");
}

static long long
	ft_get_reverse_num(int n)
{
	long long	num;

	num = 0;
	if (n == -2147483648)
		num = 8463847412;
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		num *= 10;
		num += n % 10;
		n /= 10;
	}
	return (num);
}

int
	ft_get_digit_count(long long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits++;
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int
	ft_get_zeros(int n, long long reverse)
{
	int	reverseDigits;
	int	nDigits;

	reverseDigits = ft_get_digit_count(reverse);
	nDigits = ft_get_digit_count(n);
	if (n < 0)
		nDigits--;
	if (n == 0)
		return (1);
	return (nDigits - reverseDigits);
}

char
	*ft_itoa(int n)
{
	long long		reverse;
	int				zeros;
	static char		*dup;
	char			*dup_copy;

	reverse = ft_get_reverse_num(n);
	zeros = ft_get_zeros(n, reverse);
	dup = (char *)malloc(ft_get_digit_count(n) * sizeof(char) + 1);
	if (dup == 0)
		return (0);
	dup_copy = dup;
	if (n < 0)
		*dup_copy++ = '-';
	while (reverse > 0)
	{
		*dup_copy++ = (reverse % 10) + '0';
		reverse /= 10;
	}
	while (zeros > 0)
	{
		*dup_copy++ = '0';
		zeros--;
	}
	*dup_copy++ = '\0';
	return (dup);
}
