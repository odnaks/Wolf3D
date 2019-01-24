/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:37:30 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/05 16:20:16 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (len > size)
		return (ft_strlen(src) + size);
	while (src[i] && len < size - 1)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	while (src[i])
	{
		i++;
		len++;
	}
	return (len);
}
