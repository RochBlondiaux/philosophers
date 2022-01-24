/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:54:01 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/24 14:11:09 by rblondia         ###   ########.fr       */
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
	pthread_mutex_destroy(&app->somebody_dead);
}

void	clear_philosophers(t_app *app)
{
	size_t			i;
	t_philosopher	*philosopher;
	void			*retval;

	if (!app)
		return ;
	i = 0;
	while (app->settings.philosophers > i)
	{
		philosopher = app->philosophers[i];
		pthread_join(philosopher->monitor_thread, &retval);
		pthread_join(philosopher->thread, &retval);
		pthread_mutex_destroy(&philosopher->mutex);
		pthread_mutex_destroy(&philosopher->eat_mutex);
		free(philosopher);
		i++;
	}
	free(app->philosophers);
	clear_forks_(app);
}
