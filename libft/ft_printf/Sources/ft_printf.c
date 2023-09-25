/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:13:24 by chonorat          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:08 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		index;
	int		strlength;
	int		check_error;
	va_list	param;

	va_start(param, str);
	strlength = 0;
	index = 0;
	check_error = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			check_error = ft_get_type(str[index++], param);
		}
		else
			check_error = ft_putchar_fd(str[index++], 1);
		if (check_error == -1)
			return (va_end(param), -1);
		strlength += check_error;
	}
	return (va_end(param), strlength);
}
