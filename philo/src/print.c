/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:40 by ygille            #+#    #+#             */
/*   Updated: 2025/01/27 16:47:02 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message_printer(int id, char *message, t_philo_infos *philo)
{
	t_timeval	now;

	while (gettimeofday(&now, NULL) == -1)
		;
	if (philo->started == 0)
		return ;
	printf("%ld %d %s", now.tv_sec * 1000 + now.tv_usec / 1000, id + 1,
		message);
}

void	death_printer(int id)
{
	t_timeval	now;

	while (gettimeofday(&now, NULL) == -1)
		;
	printf("%ld %d %s", now.tv_sec * 1000 + now.tv_usec / 1000, id + 1,
		MESSAGE_DIED);
}
