/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 15:16:57 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	join_threads(t_app *app)
{
	size_t	i;

	i = -1;
	while (app->philosophers[++i])
		pthread_join(app->philosophers[i]->thread, NULL);
}

static t_philosopher	*get_dead(t_app *app)
{
	size_t	i;

	i = -1;
	while (app->philosophers[++i])
	{
		if (should_be_dead(app->philosophers[i]))
			return (app->philosophers[i]);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_app			*app;
	t_philosopher	*philosopher;
	size_t			running;

	app = (t_app *) arg;
	running = 1;
	while (running)
	{
		if (anyone_dead(app) || everyone_is_full(app))
			running = 0;
	}
	join_threads(app);
	pthread_mutex_unlock(&app->somebody_dead);
	usleep(1000);
	philosopher = get_dead(app);
	if (philosopher)
		set_state(philosopher, DEAD);
	return ((void *) 0);
}

void	*live(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	init(philosopher);
	while (1)
	{
		set_state(philosopher, THINKING);
		take_forks(philosopher);
		eat(philosopher);
		clear_forks(philosopher);
	}
	return ((void *) 0);
}
