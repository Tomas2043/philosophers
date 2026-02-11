/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:09:35 by toandrad          #+#    #+#             */
/*   Updated: 2026/02/11 13:12:47 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				death_flag;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	int				left_fork;
	int				right_fork;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
}	t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
void	ft_usleep(long ms);

int		is_valid_positive_number(char *str);
int		parse_args(int ac, char **av, t_data *data);

int		init_data(t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_philo **philos, t_data *data);

void	print_status(t_philo *philo, char *status);
void	*philo_routine(void *arg);

#endif