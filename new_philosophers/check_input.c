/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:48:36 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/05 11:48:57 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

static int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!check_digits(argv))
		return (0);
	return (1);
}
