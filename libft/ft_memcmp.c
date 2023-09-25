/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:43:02 by chonorat          #+#    #+#             */
/*   Updated: 2022/12/05 15:43:03 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;
	size_t			index;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (unsigned_s1[index] - unsigned_s2[index] != 0)
			return (unsigned_s1[index] - unsigned_s2[index]);
		index++;
	}
	return (0);
}
