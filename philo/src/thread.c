/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:10:48 by ygille            #+#    #+#             */
/*   Updated: 2025/01/24 15:28:01 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo_infos *infos)
{
	int		i;

	i = 0;
	while (i < infos->nb_philo)
	{
		init_philo(i, infos);
		if (pthread_create(&infos->philos[i].thread,
			NULL, philo_thread, (void *)&infos->philos[i]))
		{
			infos->err = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_philo(int i, t_philo_infos *infos)
{
	infos->philos[i].id = i;
	infos->philos[i].l_fork = i;
	infos->philos[i].r_fork = (i + 1) % infos->nb_philo;
	infos->philos[i].eated_times = 0;
	infos->philos[i].infos = infos;
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->infos->started)
		if (philo->infos->err)
			return (NULL);
	pthread_mutex_lock(&philo->lock_eat);
	while (gettimeofday(&philo->eated_at, NULL) == -1);
	pthread_mutex_unlock(&philo->lock_eat);
	while (philo->infos->started)
	{
	}
	return (NULL);
}
