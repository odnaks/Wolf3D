/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:06:56 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/07 17:25:36 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_free(t_list **alst)
{
	t_list *next;
	t_list *tmp;

	if (!alst || !*alst)
		return ;
	next = *alst;
	while (next)
	{
		tmp = next;
		next = next->next;
		free(tmp);
	}
	*alst = NULL;
}
