/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:28:08 by chonorat          #+#    #+#             */
/*   Updated: 2023/01/07 14:44:12 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*begin_lst;

	if (!lst || !f || !del)
		return (NULL);
	begin_lst = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_lst, new_lst);
		lst = lst->next;
	}
	return (begin_lst);
}
