/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:25:21 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 16:21:12 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void check(t_app *app, t_philosopher *philosopher)
{
	if (is_state(philosopher, DEAD))
		app->running = 0;
}

void init(t_philosopher *philosopher)
{
	int id;

	id = philosopher->index;
	philosopher->last_meal = get_time();
	philosopher->last_nap = get_time();
	philosopher->limit = get_time() + (philosopher->settings.time_to_die);
	philosopher->left_fork = id - 1;
	philosopher->right_fork = (id) % philosopher->settings.philosophers;
	philosopher->meals = 0;
}

int main(int argc, char **argv)
{
	t_app app;

	app.running = 0;
	parse_settings(&app.settings, argc, argv);
	if (!validate_settings(app.settings))
		return (EXIT_FAILURE);
	create_philosophers(&app);
	if (!app.philosophers)
		return (EXIT_FAILURE);
	if (!app.forks) {
		clear_philosophers(&app);
		return (EXIT_FAILURE);
	}
	start(&app);
	app.running = 1;
	while (app.running) {
		foreach(&app, &check);
		usleep(20);
	}
	clear_philosophers(&app);
	return (EXIT_SUCCESS);
}
