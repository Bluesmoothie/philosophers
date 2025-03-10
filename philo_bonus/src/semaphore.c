/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:31 by ygille            #+#    #+#             */
/*   Updated: 2025/02/20 14:40:48 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_semaphores(t_philo_infos *infos)
{
	int		i;
	char	a[2];

	i = 0;
	a[1] = '\0';
	while (i < infos->nb_philo)
	{
		a[0] = i + 1;
		infos->philos[i++].eating = sem_open((char *)a, O_CREAT, 0777, 1);
	}
	infos->forks = sem_open(SEM_FORKS, O_CREAT, 0777, infos->nb_philo);
	return (0);
}

int	deinit_semaphores(t_philo_infos *infos)
{
	int		i;
	char	a[2];

	i = 0;
	a[1] = '\0';
	while (i < infos->nb_philo)
	{
		sem_close(infos->philos[i++].eating);
		a[0] = i;
		sem_unlink((char *)a);
	}
	sem_close(infos->forks);
	sem_unlink(SEM_FORKS);
	return (0);
}

void	clean_semaphores(t_philo_infos *infos)
{
	int	i;

	i = 0;
	infos->started = 0;
	while (i < infos->nb_philo)
		pthread_join(infos->philos[i++].thread, NULL);
	deinit_semaphores(infos);
}
