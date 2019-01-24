/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:08:28 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/06 19:18:01 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_length(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = number_length(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[0] = '0';
	if (n < 0)
		str[0] = '-';
	n = ft_abs(n);
	while (n != 0)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
