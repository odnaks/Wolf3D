/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:32:57 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/06 19:58:13 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	const char	*ptr;

	if (!s)
		return (NULL);
	while (is_whitespace(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	ptr = s + ft_strlen(s) - 1;
	while (is_whitespace(*ptr))
		ptr--;
	return (ft_strsub(s, 0, ptr - s + 1));
}
