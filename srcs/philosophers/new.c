/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/14 19:08:13 by rblondia         ###   ########.fr       */
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

static void	set_previous(t_app *app)
{
	size_t	i;
	int		result;

	i = 1;
	app->philosophers[0]->previous
		= app->philosophers[app->settings.philosophers - 1];
	while (i < app->settings.philosophers)
	{
		app->philosophers[i]->previous = app->philosophers[i - 1];
		i++;
	}
	set_state(app->philosophers[0]->previous, EATING);
	i = 0;
	while (i < app->settings.philosophers)
	{
		result = pthread_create(&(app->philosophers[i])->thread,
				NULL, &live, app->philosophers[i]);
		if (!validate_thread(result))
			break ;
		i++;
	}
}

void	create_philosophers(t_app *app)
{
	size_t			i;
	t_philosopher	*new;

	create_forks(app);
	app->philosophers = malloc(sizeof (t_philosopher)
			* (app->settings.philosophers + 1));
	if (!app->philosophers)
	{
		app->philosophers = NULL;
		return ;
	}
	i = 1;
	while (i <= app->settings.philosophers)
	{
		new = create_philosopher(app, i);
		if (!new)
		{
			clear_philosophers(app);
			break ;
		}
		app->philosophers[i - 1] = new;
		i++;
	}
	app->philosophers[i - 1] = NULL;
	set_previous(app);
}
