/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:43 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/24 10:04:28 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	take_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	set_state(philosopher, TAKING_FORK);
	pthread_mutex_lock(&philosopher->app->forks[philosopher->right_fork]);
	set_state(philosopher, TAKING_FORK);
	set_state(philosopher, EATING);
}

void	clear_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->left_fork]);
	set_state(philosopher, SLEEPING);
	usleep(get_waiting_time(philosopher, SLEEPING));
}
