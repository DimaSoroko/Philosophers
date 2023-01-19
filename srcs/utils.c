/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:58:23 by dsoroko           #+#    #+#             */
/*   Updated: 2022/12/22 09:41:10 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	if (vars->philos)
		ft_free(vars);
	return (-1);
}

void	ft_free(t_vars *vars)
{
	if (vars->philos[0].index)
	{
		free(&vars->forks[0]);
		free(&vars->philos[0]);
	}
}

void	output_msg(t_philo *philo, unsigned long time, char d)
{
	pthread_mutex_lock(&philo->vars->output);
	if (d == 'd')
		printf("%lu %d died\n", time, philo->index);
	if (d == 'x')
		printf("%lu all philosophers ate enough\n", time);
	if (is_stopped(philo->vars))
	{
		pthread_mutex_unlock(&philo->vars->output);
		return ;
	}
	if (d == 'f')
		printf("%lu %d has taken a fork\n", time, philo->index);
	if (d == 'e')
		printf("%lu %d is eating\n", time, philo->index);
	if (d == 's')
		printf("%lu %d is sleeping\n", time, philo->index);
	if (d == 't')
		printf("%lu %d is thinking\n", time, philo->index);
	pthread_mutex_unlock(&philo->vars->output);
}

void	stop_simulation(t_vars *vars)
{
	pthread_mutex_lock(&vars->stop);
		vars->stopped = 1;
	pthread_mutex_unlock(&vars->stop);
}

int	is_stopped(t_vars *vars)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&vars->stop);
	if (vars->stopped == 1)
		flag = 1;
	pthread_mutex_unlock(&vars->stop);
	return (flag);
}
