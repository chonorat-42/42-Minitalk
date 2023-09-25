/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:33:56 by chonorat          #+#    #+#             */
/*   Updated: 2023/03/14 15:24:37 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

static int	ft_hexa_counter(unsigned int value)
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

int	ft_puthexa(unsigned int hexa_convert, char type, int check_error)
{
	if (hexa_convert >= 16)
	{
		ft_puthexa(hexa_convert / 16, type, check_error);
		ft_puthexa(hexa_convert % 16, type, check_error);
	}
	else if (type == 'x')
		check_error = (ft_putchar_fd("0123456789abcdef"[hexa_convert], 1));
	else if (type == 'X')
		check_error = (ft_putchar_fd("0123456789ABCDEF"[hexa_convert], 1));
	return (check_error);
}

int	ft_type_hexa(va_list param, char type)
{
	unsigned int	value;
	int				check_error;

	check_error = 0;
	value = va_arg(param, unsigned int);
	if (value == 0)
		return (ft_putchar_fd('0', 1));
	if (ft_puthexa(value, type, check_error) == -1)
		return (-1);
	return (ft_hexa_counter(value));
}
