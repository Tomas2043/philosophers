/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:59:43 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/11 13:02:57 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	if (parse_args(ac, av, &data) != 0)
		return (1);
	if (init_data(&data) != 0)
		return (printf("Error: Initialization failed\n"), 1);
	if (init_philos(&philos, &data) != 0)
		return (printf("Error: Philosopher init failed\n"), 1);
	i = 0;
	while (i < data.number_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < data.number_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	printf("All philosophers finished.");
	return (0);
}
