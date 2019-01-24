/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:29:25 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/07 17:12:21 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*new_list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(new_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin_list = new_list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new_list->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_list_free(&begin_list);
			return (NULL);
		}
		lst = lst->next;
		new_list = new_list->next;
	}
	return (begin_list);
}
