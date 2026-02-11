/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:06:51 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/10 13:36:29 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (printf("Error: Invalid arguments!\n"), 1);
	if (!is_valid_positive_number(av[1]))
		return (printf("Error: Invalid number of philosophers!\n"), 1);
	if (!is_valid_positive_number(av[2]))
		return (printf("Error: Invalid time to die!\n"), 1);
	if (!is_valid_positive_number(av[3]))
		return (printf("Error: Invalid time to eat!\n"), 1);
	if (!is_valid_positive_number(av[4]))
		return (printf("Error: Invalid time to sleep!\n"), 1);
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (!is_valid_positive_number(av[5]))
			return (printf("Error: Invalid meal count!\n"), 1);
		data->must_eat_count = ft_atoi(av[5]);
	}
	else
		data->must_eat_count = -1;
	return (0);
}

int	is_valid_positive_number(char *str)
{
	int	i;
	int	nr;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	nr = ft_atoi(str);
	if (nr <= 0)
		return (0);
	return (1);
}
