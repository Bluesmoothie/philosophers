/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:51:36 by ygille            #+#    #+#             */
/*   Updated: 2025/02/07 14:36:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_infos	*infos;
	int				i;

	if (!(argc == 5 || argc == 6))
		return (error(NB_ARG_ERROR));
	i = 1;
	while (i < argc)
		if (verify_arg(argv[i++]))
			return (error(ARG_ERROR));
	infos = init_struct(argc, argv);
	if (!infos)
		return (error(MALLOC_ERROR));
	if (init_mutex(infos))
			return (free_error(infos, MUTEX_ERROR));
	if (create_threads(infos))
		return (free_error(infos, THREAD_ERROR));
	philo_start(infos);
	while (infos->started)
	{
		usleep(1000);
		verifs(infos);
	}
	cleanup_thread_mutex(infos);
	free(infos);
	return (0);
}

int	verify_arg(char *arg)
{
	int		i;
	long	test;

	if (ft_strlen(arg) == 0 || ft_strlen(arg) > 10)
		return (1);
	test = ft_atol(arg);
	if (test < 0 || test > INT_MAX)
		return (1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

t_philo_infos	*init_struct(int argc, char **argv)
{
	t_philo_infos	*infos;

	infos = malloc(sizeof(t_philo_infos));
	if (!infos)
		return (NULL);
	infos->nb_philo = ft_atoi(argv[1]);
	infos->time_to_die = ft_atoi(argv[2]);
	infos->time_to_eat = ft_atoi(argv[3]);
	infos->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		infos->nb_eat = ft_atoi(argv[5]);
	else
		infos->nb_eat = -1;
	infos->started = 0;
	infos->err = 0;
	return (infos);
}

int	free_error(t_philo_infos *infos, int error_code)
{
	free(infos);
	return (error(error_code));
}

int	error(int error_code)
{
	if (error_code == NB_ARG_ERROR)
		write(2, "Error: wrong number of arguments\n", 33);
	else if (error_code == MALLOC_ERROR)
		write(2, "Error: malloc failed\n", 21);
	else if (error_code == ARG_ERROR)
		write(2, "Error: wrong argument\n", 23);
	else if (error_code == MUTEX_ERROR)
		write(2, "Error: mutex init failed\n", 26);
	else if (error_code == THREAD_ERROR)
		write(2, "Error: thread creation failed\n", 31);
	return (1);
}
