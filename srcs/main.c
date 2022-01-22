/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:25:21 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/22 13:57:44 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init(t_philosopher *philosopher)
{
	int	id;

	id = philosopher->index;
	philosopher->limit = get_time() + (philosopher->settings.time_to_die);
	philosopher->left_fork = id - 1;
	philosopher->right_fork = (id) % philosopher->settings.philosophers;
	pthread_mutex_init(&philosopher->eat_mutex, NULL);
	pthread_mutex_init(&philosopher->mutex, NULL);
	pthread_mutex_lock(&philosopher->eat_mutex);
}

static int	launch_eat_monitor_thread(t_app *app)
{
	pthread_t	tid;

	if (app->settings.must_eat_time == -1)
		return (1);
	if (pthread_create(&tid, NULL, eat_monitor, app) != 0)
		return (0);
	pthread_detach(tid);
	return (1);
}

static void	start_app(t_app *app)
{
	pthread_mutex_init(&app->somebody_dead, NULL);
	pthread_mutex_lock(&app->somebody_dead);
	pthread_mutex_lock(&app->somebody_dead);
	pthread_mutex_unlock(&app->somebody_dead);
	clear_philosophers(app);
}

int	main(int argc, char **argv)
{
	t_app	app;

	parse_settings(&app.settings, argc, argv);
	if (!validate_settings(app.settings))
		return (EXIT_FAILURE);
	create_philosophers(&app);
	if (!app.philosophers)
		return (EXIT_FAILURE);
	if (!app.forks)
	{
		clear_philosophers(&app);
		return (EXIT_FAILURE);
	}
	if (!launch_eat_monitor_thread(&app))
	{
		clear_philosophers(&app);
		return (EXIT_FAILURE);
	}
	start(&app);
	start_app(&app);
	return (EXIT_SUCCESS);
}
