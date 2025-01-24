/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:40 by ygille            #+#    #+#             */
/*   Updated: 2025/01/24 15:31:41 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message_printer(int id, char *message)
{
	t_timeval	now;

	while (gettimeofday(&now, NULL) == -1)
		;
	printf("%ld %d %s", now.tv_usec, id + 1, message);
}
