/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:52:03 by ygille            #+#    #+#             */
/*   Updated: 2025/02/20 14:08:44 by ygille           ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>

# define MAX_PHILO		256

# define MESSAGE_DIED	"died\n"
# define MESSAGE_EAT	"is eating\n"
# define MESSAGE_SLEEP	"is sleeping\n"
# define MESSAGE_THINK	"is thinking\n"
# define MESSAGE_FORK	"has taken a fork\n"

# define SEM_EAT		"eating"
# define SEM_FORKS		"forks"

typedef struct timeval			t_timeval;
typedef struct s_philo_infos	t_philo_infos;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eated_times;
	t_timeval		eated_at;
	pthread_t		thread;
	sem_t			*eating;
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
	t_timeval		start;
	t_philo			philos[MAX_PHILO];
	sem_t			*forks;
}	t_philo_infos;

enum e_error_codes
{
	NB_ARG_ERROR,
	MALLOC_ERROR,
	ARG_ERROR,
	SEM_ERROR,
	THREAD_ERROR
};

// philo.c
int				verify_arg(char *arg);
t_philo_infos	*init_struct(int argc, char **argv);
int				free_error(t_philo_infos *infos, int error_code);
int				error(int error_code);

// print.c
void			message_printer(int id, char *message, t_philo_infos *philo);
void			death_printer(int id, t_philo_infos *philo);

// semaphore.c
int				init_semaphores(t_philo_infos *infos);
int				deinit_semaphores(t_philo_infos *infos);
void			clean_semaphores(t_philo_infos *infos);

// thread.c
int				create_threads(t_philo_infos *infos);
void			init_philo(int i, t_philo_infos *infos);
void			*philo_thread(void *arg);
void			philo_eat(t_philo *philo);
void			philo_sleep(int time);

// utils.c
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
size_t			ft_strlen(const char *s);
void			philo_start(t_philo_infos *infos);
long int		calc_timestamp(t_timeval start);

// verif.c
void			verif_eat(t_philo_infos *infos);
void			verif_die(t_philo_infos *infos);
void			verifs(t_philo_infos *infos);

#endif