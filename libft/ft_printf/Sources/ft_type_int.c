/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:12:51 by chonorat          #+#    #+#             */
/*   Updated: 2023/03/15 15:23:28 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_count_int(int value)
{
	int			index;
	int			negative;
	long int	long_value;

	index = 0;
	negative = 0;
	long_value = value;
	if (long_value < 0)
	{
		long_value *= -1;
		negative = 1;
	}
	while (long_value > 0)
	{
		index++;
		long_value /= 10;
	}
	if (negative)
		index++;
	return (index);
}

int	ft_type_int(va_list param)
{
	int	value;
	int	check_error;

	value = va_arg(param, int);
	check_error = 0;
	if (value == 0)
		return (ft_putchar_fd('0', 1));
	else
	{
		check_error = ft_putnbr_fd(value, 1);
		if (check_error == -1)
			return (check_error);
		return (ft_count_int(value));
	}
}
