/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:35:21 by chonorat          #+#    #+#             */
/*   Updated: 2023/02/08 15:52:53 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_hexa_counter_ptr(long unsigned int value)
{
	int	counter;

	counter = 0;
	while (value > 0)
	{
		counter++;
		value /= 16;
	}
	return (counter);
}

int	ft_puthexa_ptr(long unsigned int hexa_convert, int check_error)
{
	if (hexa_convert >= 16)
	{
		ft_puthexa_ptr(hexa_convert / 16, check_error);
		ft_puthexa_ptr(hexa_convert % 16, check_error);
	}
	else
		check_error = (ft_putchar_fd("0123456789abcdef"[hexa_convert], 1));
	return (check_error);
}

int	ft_type_ptr(va_list param)
{
	long unsigned int	value;
	int					check_error;

	value = va_arg(param, long unsigned int);
	if (value == 0)
	{
		check_error = (ft_putstr_fd("(nil)", 1));
		if (check_error == -1)
			return (-1);
		return (5);
	}
	else
	{
		check_error = ft_putstr_fd("0x", 1);
		if (check_error == -1)
			return (-1);
		if (ft_puthexa_ptr(value, check_error) == -1)
			return (-1);
		return (ft_hexa_counter_ptr(value) + 2);
	}
}
