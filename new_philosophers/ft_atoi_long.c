/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:46:41 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/07 10:44:45 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

signed long long	ft_atoi_long(const char	*string)
{
	int			i;
	long long	sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((string[i] <= 13 && string[i] >= 9) || string[i] == 32)
		i++;
	if (string[i] == 45)
		sign *= -1;
	if (string[i] == 43 || string[i] == 45)
		i++;
	while (string[i] == '0')
		i++;
	while (string[i] >= 48 && string[i] <= 57)
		number = (number) * 10 + (string[i++] - 48);
	return (sign * number);
}
