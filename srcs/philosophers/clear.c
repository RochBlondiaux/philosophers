/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:54:01 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 14:05:29 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	clear_forks_(t_app *app)
{
	size_t	i;

	i = 0;
	while (app->settings.philosophers > i)
	{
		pthread_mutex_destroy(&app->forks[i]);
		i++;
	}
	free(app->forks);
}

void	clear_philosophers(t_app *app)
{
	size_t			i;
	t_philosopher	*philosopher;

	if (!app)
		return ;
	i = 0;
	pthread_join(app->monitor, NULL);
	while (app->settings.philosophers > i)
	{
		philosopher = app->philosophers[i];
		free(philosopher);
		i++;
	}
	free(app->philosophers);
	clear_forks_(app);
	pthread_mutex_destroy(&app->somebody_dead);
}
