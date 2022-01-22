/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/22 14:07:23 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*eat_monitor(void *arg)
{
	t_app	*app;
	int		current;
	int		total;
	int		i;

	app = (t_app *) arg;
	total = app->settings.must_eat_time;
	current = 0;
	while (current < total)
	{
		i = 0;
		while (app->philosophers[i])
		{
			pthread_mutex_lock(&app->philosophers[i++]->eat_mutex);
			i++;
		}
		current++;
	}
	pthread_mutex_unlock(&(app->somebody_dead));
	return ((void *) 0);
}

static void	*monitor(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	while (1)
	{
		pthread_mutex_lock(&philosopher->mutex);
		if (should_be_dead(philosopher))
			break ;
		pthread_mutex_unlock(&philosopher->mutex);
		usleep(100);
	}
	set_state(philosopher, DEAD);
	pthread_mutex_unlock(&philosopher->mutex);
	pthread_mutex_unlock(&(philosopher->app->somebody_dead));
	return ((void *) 0);
}

static int	launch_monitor_thread(t_philosopher *philosopher)
{
	int			result;

	result = pthread_create(&philosopher->monitor_thread,
			NULL, monitor, philosopher);
	pthread_detach(philosopher->monitor_thread);
	return (result);
}

void	*live(void *arg)
{
	t_philosopher	*philosopher;
	int				result;

	philosopher = (t_philosopher *) arg;
	result = launch_monitor_thread(philosopher);
	if (result != 0)
		return ((void *) 1);
	while (1)
	{
		take_forks(philosopher);
		eat(philosopher);
		clear_forks(philosopher);
		set_state(philosopher, THINKING);
	}
	return ((void *) 0);
}
