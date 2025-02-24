/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:32:39 by ygille            #+#    #+#             */
/*   Updated: 2025/02/24 08:34:39 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_solo(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->forks[philo->l_fork]);
	message_printer(philo->id, MESSAGE_FORK, philo->infos);
	while (philo->infos->started == 1)
		usleep(50);
	pthread_mutex_unlock(&philo->infos->forks[philo->l_fork]);
}
