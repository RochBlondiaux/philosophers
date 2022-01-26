/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:35 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 15:17:59 by rblondia         ###   ########.fr       */
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
	return (philosopher);
}

static void	create_forks(t_app *app)
{
	size_t			i;

	app->forks = malloc(sizeof (pthread_mutex_t)
			* (app->settings.philosophers + 1));
	if (!app->forks)
		return ;
	i = 0;
	while (i < app->settings.philosophers)
	{
		pthread_mutex_init(&app->forks[i], NULL);
		i++;
	}
}

void	start(t_app *app)
{
	size_t	i;
	int		result;

	i = 0;
	while (app->settings.philosophers > i)
	{
		if (i % 2 == 1)
			usleep(1000);
		result = pthread_create(&(app->philosophers[i])->thread,
				NULL, &live, app->philosophers[i]);
		if (result != 0)
		{
			clear_philosophers(app);
			return ;
		}
		pthread_detach(app->philosophers[i]->thread);
		i++;
	}
}

void	create_philosophers(t_app *app)
{
	size_t			i;

	create_forks(app);
	app->philosophers = malloc(sizeof (t_philosopher *)
			* (app->settings.philosophers + 1));
	if (!app->philosophers)
	{
		app->philosophers = NULL;
		return ;
	}
	i = 0;
	while (app->settings.philosophers > i)
	{
		app->philosophers[i] = create_philosopher(app, i + 1);
		if (!app->philosophers[i])
		{
			clear_philosophers(app);
			return ;
		}
		i++;
	}
	app->philosophers[i] = NULL;
}
