/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:59:43 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/12 15:37:17 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	cleanup(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		i++;
	}
	free(philos);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philos;

	if (parse_args(ac, av, &data) != 0)
		return (1);
	if (init_data(&data) != 0)
		return (printf("Error: Initialization failed\n"), 1);
	if (init_philos(&philos, &data) != 0)
		return (printf("Error: Philosopher init failed\n"), 1);
	init_threads(data, philos);
	cleanup(philos, &data);
	printf("All philosophers finished.");
	return (0);
}
