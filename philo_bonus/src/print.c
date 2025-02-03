/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:40 by ygille            #+#    #+#             */
/*   Updated: 2025/01/28 14:15:06 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message_printer(int id, char *message, t_philo_infos *philo)
{
	if (philo->started == 0)
		return ;
	printf("%ld %d %s", calc_timestamp(philo->start), id + 1, message);
}

void	death_printer(int id, t_philo_infos *philo)
{
	printf("%ld %d %s", calc_timestamp(philo->start), id + 1, MESSAGE_DIED);
}
