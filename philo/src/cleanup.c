/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:10:12 by ygille            #+#    #+#             */
/*   Updated: 2025/01/24 14:43:10 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_thread_mutex(t_philo_infos *infos)
{
	philo->infos->started = 0;
	clean_mutex(infos);
	return (0);
}
