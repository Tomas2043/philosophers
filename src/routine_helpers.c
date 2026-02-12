/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:00:51 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/12 14:53:50 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_simulation_end(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->data->death_mutex);
	end = philo->data->death_flag;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (end);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[0]);
	print_status(philo, "has taken a fork");
	while (!check_simulation_end(philo))
		ft_usleep(1);
	pthread_mutex_unlock(&philo->data->forks[0]);
}
