/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:12:00 by ygille            #+#    #+#             */
/*   Updated: 2025/02/03 18:47:33 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	verif_eat(t_philo_infos *infos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < infos->nb_philo)
	{
		sem_wait(infos->eating);
		if (infos->philos[i].eated_times > infos->nb_eat)
			count++;
		sem_post(infos->eating);
		i++;
	}
	if (count == i)
	{
		infos->started = 0;
		write(1, "All philos ate enough\n", 22);
	}
}

void	verif_die(t_philo_infos *infos)
{
	int			i;
	t_timeval	now;

	i = 0;
	while (i < infos->nb_philo)
	{
		while (gettimeofday(&now, NULL) == -1)
			;
		sem_wait(infos->eating);
		if ((now.tv_sec - infos->philos[i].eated_at.tv_sec) * 1000
			+ (now.tv_usec - infos->philos[i].eated_at.tv_usec) / 1000
			> infos->time_to_die)
		{
			sem_post(infos->eating);
			infos->started = 0;
			death_printer(infos->philos[i].id, infos);
			return ;
		}
		sem_post(infos->eating);
		i++;
	}
}

void	verifs(t_philo_infos *infos)
{
	if (infos->nb_eat != -1)
		verif_eat(infos);
	verif_die(infos);
}
