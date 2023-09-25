/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:39:41 by chonorat          #+#    #+#             */
/*   Updated: 2023/08/14 15:35:59 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../../libft.h"

int	ft_printf(const char *str, ...);

int	ft_get_type(char type, va_list param);
int	ft_type_char(va_list param);
int	ft_type_str(va_list param);
int	ft_type_int(va_list param);
int	ft_type_unsigned(va_list param);
int	ft_type_hexa(va_list param, char type);
int	ft_type_ptr(va_list param);

#endif
