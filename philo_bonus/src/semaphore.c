/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:31 by ygille            #+#    #+#             */
/*   Updated: 2025/02/03 18:46:08 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_semaphores(t_philo_infos *infos)
{
	infos->eating = sem_open(SEM_EAT, O_CREAT, 0777, 1);
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
	infos->started = 0;
	deinit_semaphores(infos);
}
