/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:52:05 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 18:00:40 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	while (i > 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}
