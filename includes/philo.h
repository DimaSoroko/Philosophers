/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:46 by dsoroko           #+#    #+#             */
/*   Updated: 2023/01/13 11:00:28 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index;
	int				ate_num;
	unsigned long	last_eat;
	pthread_t		thread;
	pthread_mutex_t	philo_m;
	struct s_vars	*vars;
}	t_philo;

typedef struct s_vars
{
	int				philo_num;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				must_eat;
	pthread_mutex_t	output;
	pthread_mutex_t	stop;
	pthread_mutex_t	*forks;
	unsigned long	start_time;
	t_philo			*philos;
	int				stopped;
}	t_vars;

int				ft_error(char *str, t_vars *vars);
int				ft_atoi(char *str);
int				init_vars(t_vars *vars, int argc, char **argv);
void			init_philos(t_vars *vars);
int				init_mutex(t_vars *vars);
void			*thread_handler(void *ptr);
unsigned long	get_time(void);
unsigned long	get_timestamp(t_vars *vars);
void			monitoring(t_vars *vars);
void			ft_sleep(int milisec);
int				start_simulation(t_vars *vars);
void			stop_simulation(t_vars *vars);
void			start_eating(t_philo *philo, t_vars *vars);
void			join_threads(t_vars *vars);
void			output_msg(t_philo *philo, unsigned long time, char d);
int				is_stopped(t_vars *vars);
void			ft_free(t_vars *vars);
int				philos_ate(t_vars *vars);

#endif