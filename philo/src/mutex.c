/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:31 by ygille            #+#    #+#             */
/*   Updated: 2025/01/24 14:44:39 by ygille           ###   ########.fr       */
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
			return (clean_mutex_err(infos, i, 0);
		if (pthread_mutex_init(&infos->philos[i].lock_eat, NULL))
			return (clean_mutex_err(infos, i, 1);
		i++;
	}
	return (0);
}

int	clean_mutex_err(t_philo_infos *infos, int max, int state)
{
	int	i;

	i = 0;
	while (i < max - 1)
	{
		pthread_mutex_destroy(&infos->forks[i]);
		pthread_mutex_destroy(&infos->philos[i].lock_eat);
		i++;
	}
	if (state)
		pthread_mutex_destroy(&infos->forks[i]);
	return (1);
}

void	clean_mutex(t_philo_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->nb_philo)
	{
		pthread_join(infos->philos[i].thread, NULL);
		pthread_mutex_destroy(&infos->forks[i]);
		pthread_mutex_destroy(&infos->philos[i].lock_eat);
		i++;
	}
}
