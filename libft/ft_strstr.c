/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:02:01 by cmelara-          #+#    #+#             */
/*   Updated: 2018/11/26 18:23:27 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;
	size_t	tmp;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			tmp = i;
			while (haystack[i++] == needle[j] && needle[j])
			{
				j++;
			}
			i = tmp;
			if (j == needle_len)
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
