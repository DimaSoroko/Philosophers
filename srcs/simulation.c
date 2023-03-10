/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:15:48 by dsoroko           #+#    #+#             */
/*   Updated: 2023/01/10 12:01:18 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* function creats one thread per philo */
int	start_simulation(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->start_time)
		vars->start_time = get_time();
	while (i < vars->philo_num)
	{
		if (pthread_create(&vars->philos[i].thread,
				NULL, thread_handler, &vars->philos[i]))
			return (-1);
		i++;
	}
	monitoring(vars);
	join_threads(vars);
	pthread_mutex_destroy(&vars->output);
	pthread_mutex_destroy(&vars->stop);
	return (0);
}

void	join_threads(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->philo_num == 1)
		pthread_detach(vars->philos[0].thread);
	while (vars->philos[i].thread)
	{
		pthread_join(vars->philos[i].thread, NULL);
		pthread_mutex_destroy(&vars->philos[i].philo_m);
		i++;
	}
	free(&vars->forks[0]);
	free(&vars->philos[0]);
}

/* check death*/
void	monitoring(t_vars *vars)
{
	int	i;

	i = 0;
	while (!is_stopped(vars))
	{
		pthread_mutex_lock(&vars->philos[i].philo_m);
		if ((int)(get_timestamp(vars) - vars->philos[i].last_eat)
			>= vars->to_die)
		{
			stop_simulation(vars);
			output_msg(&vars->philos[i], get_timestamp(vars), 'd');
		}
		pthread_mutex_unlock(&vars->philos[i].philo_m);
		if (philos_ate(vars))
		{
			stop_simulation(vars);
			output_msg(&vars->philos[i], get_timestamp(vars), 'x');
		}
		if (i < vars->philo_num - 1)
			i++;
		else
			i = 0;
	}
}
