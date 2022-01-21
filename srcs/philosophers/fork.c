/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:43 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/21 21:11:22 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	take_forks(t_philosopher *philosopher)
{
	set_state(philosopher, TAKING_FORK);
	pthread_mutex_lock(philosopher->app->forks[philosopher->left_fork]);
	printf(FORK_MSG, get_time(), philosopher->index);
	pthread_mutex_lock(philosopher->app->forks[philosopher->right_fork]);
	set_state(philosopher, EATING);
}

void	clear_forks(t_philosopher *philosopher)
{
	set_state(philosopher, SLEEPING);
	pthread_mutex_unlock(philosopher->app->forks[philosopher->right_fork]);
	pthread_mutex_unlock(philosopher->app->forks[philosopher->left_fork]);
	usleep(get_waiting_time(philosopher, SLEEPING));
}
