/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:10:48 by ygille            #+#    #+#             */
/*   Updated: 2025/02/20 14:09:03 by ygille           ###   ########.fr       */
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
	while (gettimeofday(&infos->philos[i].eated_at, NULL) == -1)
		;
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->infos->started)
		if (philo->infos->err)
			return (NULL);
	pthread_mutex_lock(&philo->lock_eat);
	while (gettimeofday(&philo->eated_at, NULL) == -1)
		;
	pthread_mutex_unlock(&philo->lock_eat);
	if (philo->id % 2)
		usleep(100);
	while (philo->infos->started)
	{
		philo_eat(philo);
		if (philo->infos->started == 0)
			break ;
		message_printer(philo->id, MESSAGE_SLEEP, philo->infos);
		philo_sleep(philo->infos->time_to_sleep);
		if (philo->infos->started == 0)
			break ;
		message_printer(philo->id, MESSAGE_THINK, philo->infos);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->forks[philo->l_fork]);
	message_printer(philo->id, MESSAGE_FORK, philo->infos);
	if (philo->infos->started == 0)
	{
		pthread_mutex_unlock(&philo->infos->forks[philo->l_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->infos->forks[philo->r_fork]);
	message_printer(philo->id, MESSAGE_FORK, philo->infos);
	message_printer(philo->id, "is eating\n", philo->infos);
	pthread_mutex_lock(&philo->lock_eat);
	philo->eated_times++;
	while (gettimeofday(&philo->eated_at, NULL) == -1)
		;
	pthread_mutex_unlock(&philo->lock_eat);
	philo_sleep(philo->infos->time_to_eat);
	pthread_mutex_unlock(&philo->infos->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->infos->forks[philo->r_fork]);
}

void	philo_sleep(int time)
{
	t_timeval	start;
	t_timeval	now;

	while (gettimeofday(&start, NULL) == -1)
		;
	while (1)
	{
		while (gettimeofday(&now, NULL) == -1)
			;
		if ((now.tv_sec - start.tv_sec) * 1000
			+ (now.tv_usec - start.tv_usec) / 1000 >= time)
			break ;
		usleep(100);
	}
}
