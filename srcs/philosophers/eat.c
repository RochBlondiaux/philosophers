/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:30:18 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/15 12:04:40 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	eat(t_philosopher *philosopher)
{
	philosopher->last_meal = get_time();
	if (get_available_forks(philosopher->app) < 2)
		return (0);
	set_state(philosopher, EATING);
	philosopher->right_fork = get_fork(philosopher->app);
	pthread_mutex_lock(philosopher->app->forks[philosopher->right_fork]);
	philosopher->left_fork = get_fork(philosopher->app);
	pthread_mutex_lock(philosopher->app->forks[philosopher->left_fork]);
	usleep (get_waiting_time(philosopher, EATING));
	philosopher->meals++;
	set_state(philosopher, THINKING);
	pthread_mutex_unlock(philosopher->app->forks[philosopher->right_fork]);
	pthread_mutex_unlock(philosopher->app->forks[philosopher->left_fork]);
	return (1);
}
