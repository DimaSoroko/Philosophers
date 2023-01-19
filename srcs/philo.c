/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:27:37 by dsoroko           #+#    #+#             */
/*   Updated: 2022/12/22 09:46:32 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 5 && argc != 6)
		return (ft_error("Inncorect amount of arguments", &vars));
	if (init_vars(&vars, argc, argv) < 0)
		return (ft_error("Init error", &vars));
	init_philos(&vars);
	if (start_simulation(&vars) < 0)
		return (ft_error("Threads error", &vars));
	return (0);
}
