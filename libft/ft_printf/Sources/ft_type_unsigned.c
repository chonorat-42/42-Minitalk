/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 03:17:33 by chonorat          #+#    #+#             */
/*   Updated: 2023/02/09 16:51:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_count_unsigned(unsigned int value)
{
	long unsigned int	long_value;
	int					count;

	count = 0;
	long_value = value;
	while (long_value > 0)
	{
		count++;
		long_value /= 10;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n, int check_error)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		check_error = write(1, &c, 1);
		return (check_error);
	}
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, check_error);
		ft_putnbr_unsigned(n % 10, check_error);
	}
	return (check_error);
}

int	ft_type_unsigned(va_list param)
{
	unsigned int	value;
	int				check_error;

	check_error = 0;
	value = va_arg(param, unsigned int);
	if (value == 0)
		return (ft_putchar_fd('0', 1));
	if (ft_putnbr_unsigned(value, check_error) == -1)
		return (-1);
	return (ft_count_unsigned(value));
}
