/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:58:14 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/11 21:41:34 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;

	if (!s)
		return (0);
	i = 0;
	w = ft_get_words_count(s, c);
	str = (char **)malloc(sizeof(char*) * (w + 1));
	if (!str)
		return (NULL);
	while (w--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub(s, 0, ft_strlen_wo_delimeter(s, c));
		if (!str[i])
			return (ft_worddel(str, i));
		s = s + ft_strlen_wo_delimeter(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
