/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:57:58 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/11 13:00:51 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philos(t_philo **philos, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!*philos)
		return (1);
	i = 0;
	while (i < data->number_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = data->start_time;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % data->number_of_philos;
		(*philos)[i].data = data;
		pthread_mutex_init(&(*philos)[i].meal_mutex, NULL);
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_data(t_data *data)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->death_flag = 0;
	data->start_time = get_time();
	if (init_forks(data) != 0)
		return (1);
	return (0);
}
