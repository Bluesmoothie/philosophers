/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:12:00 by ygille            #+#    #+#             */
/*   Updated: 2025/01/24 15:32:10 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_eat(t_philo_infos *infos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < infos->nb_philo)
	{
		pthread_mutex_lock(&infos->philos[i].lock_eat);
		if (infos->philos[i].eated_times > infos->nb_eat)
			count++;
		pthread_mutex_unlock(&infos->philos[i].lock_eat);
		i++;
	}
	if (count == i)
	{
		write(1, "All philos ate enough\n", 22);
		return (1);
	}
	return (0);
}

int	verif_die(t_philo_infos *infos)
{
	int			i;
	t_timeval	now;

	i = 0;
	while (i < infos->nb_philo)
	{
		while (gettimeofday(&now, NULL) == -1)
			;
		pthread_mutex_lock(&infos->philos[i].lock_eat);
		if (now.tv_usec - infos->philos[i].eated_at.tv_usec
			> infos->time_to_die)
		{
			pthread_mutex_unlock(&infos->philos[i].lock_eat);
			message_printer(infos->philos[i].id, MESSAGE_DIED);
			return (1);
		}
		pthread_mutex_unlock(&infos->philos[i].lock_eat);
		i++;
	}
	return (0);
}
