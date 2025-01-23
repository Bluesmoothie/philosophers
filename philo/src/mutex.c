/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:31 by ygille            #+#    #+#             */
/*   Updated: 2025/01/23 17:31:42 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_philo_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->nb_philo)
	{
		if (pthread_mutex_init(&infos->forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&infos->forks[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
