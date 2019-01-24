/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:07:50 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 14:30:01 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(src + i) == (unsigned char)c)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
