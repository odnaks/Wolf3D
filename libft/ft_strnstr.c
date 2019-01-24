/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:23:38 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 18:52:03 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;
	size_t	tmp;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			tmp = i;
			while (haystack[tmp] == needle[j] && needle[j] && tmp < len)
			{
				tmp++;
				j++;
			}
			if (j == needle_len)
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
