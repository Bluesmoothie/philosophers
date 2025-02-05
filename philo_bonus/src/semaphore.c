/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:31 by ygille            #+#    #+#             */
/*   Updated: 2025/02/05 14:56:48 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_semaphores(t_philo_infos *infos)
{
	if (infos->nb_philo == 1)
		infos->eating = sem_open(SEM_EAT, O_CREAT, 0777, 1);
	else
		infos->eating = sem_open(SEM_EAT, O_CREAT, 0777, infos->nb_philo / 2);
	infos->forks = sem_open(SEM_FORKS, O_CREAT, 0777, infos->nb_philo);
	return (0);
}

int	deinit_semaphores(t_philo_infos *infos)
{
	sem_close(infos->eating);
	sem_close(infos->forks);
	sem_unlink(SEM_EAT);
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
