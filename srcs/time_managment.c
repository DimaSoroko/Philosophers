/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:31:28 by dsoroko           #+#    #+#             */
/*   Updated: 2022/12/19 12:49:55 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	miliseconds;

	gettimeofday(&time, NULL);
	miliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (miliseconds);
}

unsigned long	get_timestamp(t_vars *vars)
{
	struct timeval	now;
	unsigned long	miliseconds;

	gettimeofday(&now, NULL);
	miliseconds = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	pthread_mutex_lock(&vars->stop);
	miliseconds = miliseconds - vars->start_time;
	pthread_mutex_unlock(&vars->stop);
	return (miliseconds);
}

void	ft_sleep(int milisec)
{
	unsigned long	time;

	time = get_time() + milisec;
	while (get_time() < time)
		usleep(100);
}
