/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:51:16 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/07 17:10:16 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long	long	n;
	int				sign;

	n = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strlen(str) >= 19 && ft_strcmp(str, "9223372036854775807") >= 0)
		return (-1);
	else if (ft_strlen(str) >= 20 &&
			ft_strcmp(str, "-9223372036854775808") >= 0)
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		n = n * 10 + (str[i++] - '0');
	return (sign * n);
}
