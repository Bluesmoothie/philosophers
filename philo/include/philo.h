/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:52:03 by ygille            #+#    #+#             */
/*   Updated: 2025/01/23 17:48:32 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define MAX_PHILO 256

typedef struct timeval t_timeval;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eated_times;
	t_timeval		eated_at;
	t_philo_infos	*infos;
}	t_philo;


typedef struct s_philo_infos
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				started;
	int				err;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];
}	t_philo_infos;

enum e_error_codes
{
	NB_ARG_ERROR = 1,
	MALLOC_ERROR = 2,
	ARG_ERROR = 3,
	MUTEX_ERROR = 4,
	THREAD_ERROR = 5
};

// philo.c
int		verify_arg(char *arg);
t_philo	*init_struct(int argc, char **argv);
int		free_error(t_philo_infos *infos, int error_code);
int		error(int error_code);

// mutex.c
int		init_mutex(t_philo_infos *infos);

// thread.c
int		create_threads(t_philo_infos *infos);
void	*philo_thread(void *arg);

// utils.c
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);

#endif