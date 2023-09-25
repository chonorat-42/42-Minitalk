/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:50:49 by chonorat          #+#    #+#             */
/*   Updated: 2023/01/18 16:10:28 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_get_type(char type, va_list param)
{
	int	lenght;

	lenght = 0;
	if (type == 'c')
		lenght = ft_type_char(param);
	else if (type == 's')
		lenght = ft_type_str(param);
	else if (type == 'd' || type == 'i')
		lenght = ft_type_int(param);
	else if (type == 'u')
		lenght = ft_type_unsigned(param);
	else if (type == 'x' || type == 'X')
		lenght = ft_type_hexa(param, type);
	else if (type == 'p')
		lenght = ft_type_ptr(param);
	else if (type == '%')
		lenght = ft_putchar_fd('%', 1);
	return (lenght);
}
