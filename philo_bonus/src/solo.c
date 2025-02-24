/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:37:47 by ygille            #+#    #+#             */
/*   Updated: 2025/02/24 08:38:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_solo(t_philo *philo)
{
	sem_wait(philo->infos->forks);
	message_printer(philo->id, MESSAGE_FORK, philo->infos);
	while (philo->infos->started == 1)
		usleep(50);
	sem_post(philo->infos->forks);
}
