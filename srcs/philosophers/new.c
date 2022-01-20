/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:35 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 16:12:24 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static t_philosopher	*create_philosopher(t_app *app, int index)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof (t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->index = index;
	philosopher->state = THINKING;
	philosopher->settings = app->settings;
	philosopher->app = app;
	philosopher->limit = 0;
	philosopher->state = THINKING;
	philosopher->eat_mutex = malloc(sizeof (pthread_mutex_t));
	if (!philosopher->eat_mutex)
		return (NULL);
	pthread_mutex_init(philosopher->eat_mutex, NULL);
	return (philosopher);
}

static void	create_forks(t_app *app)
{
	size_t			i;

	app->forks = malloc(sizeof (pthread_mutex_t *)
			* (app->settings.philosophers + 1));
	if (!app->forks)
		return ;
	i = 0;
	while (i < app->settings.philosophers)
	{
		app->forks[i] = malloc(sizeof (pthread_mutex_t));
		if (!app->forks[i])
		{
			clear_philosophers(app);
			return ;
		}
		pthread_mutex_init(app->forks[i], NULL);
		i++;
	}
	app->forks[i] = NULL;
}

void	start(t_app *app)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (app->philosophers[i])
	{
		init(app->philosophers[i]);
		result = pthread_create(&(app->philosophers[i])->thread,
								NULL, &live, app->philosophers[i]);
		if (!validate_thread(result))
			break ;
		if (pthread_detach(app->philosophers[i]->thread) != 0) {
			clear_philosophers(app);
			return ;
		}
		if (i % 2 == 1)
			usleep(10);
		i++;
	}
}

void	create_philosophers(t_app *app)
{
	size_t			i;
	t_philosopher	*new;

	create_forks(app);
	app->philosophers = malloc(sizeof (t_philosopher *)
			* (app->settings.philosophers + 1));
	if (!app->philosophers)
	{
		app->philosophers = NULL;
		return ;
	}
	i = 0;
	while (i < app->settings.philosophers)
	{
		new = create_philosopher(app, i + 1);
		if (!new)
		{
			clear_philosophers(app);
			break ;
		}
		app->philosophers[i] = new;
		i++;
	}
	app->philosophers[i] = NULL;
}
