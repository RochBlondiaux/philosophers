/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:25:21 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 13:48:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init(t_philosopher *philosopher)
{
	int	id;

	id = philosopher->index;
	philosopher->left_fork = id - 1;
	philosopher->right_fork = (id) % philosopher->settings.philosophers;
	philosopher->meals = 0;
	philosopher->limit = get_time() + philosopher->settings.time_to_die;
}

static void	start_loop(t_app *app)
{
	pthread_mutex_lock(&app->somebody_dead);
	pthread_mutex_lock(&app->somebody_dead);
	clear_philosophers(app);
}

static void	start_monitor(t_app *app)
{
	if (!pthread_create(&app->monitor, NULL, &monitor, app))
		return ;
	pthread_detach(app->monitor);
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
	pthread_mutex_init(&app.somebody_dead, NULL);
	start(&app);
	start_monitor(&app);
	start_loop(&app);
	return (EXIT_SUCCESS);
}
