/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabathur <wabathur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:37 by wabathur          #+#    #+#             */
/*   Updated: 2022/01/05 12:19:38 by wabathur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	long					current_time;
	struct timeval			time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * (unsigned int)1000 + time.tv_usec / 1000;
	return (current_time);
}
