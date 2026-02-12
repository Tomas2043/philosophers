/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:35:44 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/12 15:25:02 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philos[0].data->number_of_philos)
		{
			if (check_philo_death(&philos[i]))
				return (handle_death(&philos[i]), NULL);
			i++;
		}
		if (check_meals_eaten(philos))
		{
			pthread_mutex_lock(&philos[0].data->death_mutex);
			philos[0].data->death_flag = 1;
			pthread_mutex_unlock(&philos[0].data->death_mutex);
			return (NULL);
		}
		ft_usleep(1000);
	}
}

int	check_philo_death(t_philo *philo)
{
	long	time_without_eating;

	pthread_mutex_lock(&philo->meal_mutex);
	time_without_eating = get_time() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time_without_eating > philo->data->time_to_die)
		return (1);
	return (0);
}

void	handle_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->death_flag = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d died\n",
		get_time() - philo->data->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	check_meals_eaten(t_philo *philos)
{
	int	i;
	int	meals_eaten;

	if (philos[0].data->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < philos[0].data->number_of_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		meals_eaten = philos[i].meals_eaten;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		if (meals_eaten < philos[0].data->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}
