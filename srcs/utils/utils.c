/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:22:40 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 16:20:37 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t) 1000) + (time.tv_usec / 1000));
}

int should_be_dead(t_philosopher *philosopher)
{
	return (!is_state(philosopher, EATING) && get_time() > philosopher->limit);
}

void foreach(t_app *app, void (*f)(t_app *app, t_philosopher *philosopher))
{
	int	i;

	i = 0;
	while (app->philosophers[i]) {
		f(app, app->philosophers[i]);
		i++;
	}
}

int is_somebody_dead(t_philosopher *philosopher) {
	int		i;
	t_app	*app;

	i = 0;
	app = philosopher->app;
	while (app->philosophers[i]) {
		if (is_state(app->philosophers[i], DEAD))
			return (1);
		i++;
	}
	return (0);
}
