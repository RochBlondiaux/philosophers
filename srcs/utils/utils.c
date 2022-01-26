/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:22:40 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 14:38:26 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t) 1000) + (time.tv_usec / 1000));
}

int	should_be_dead(t_philosopher *philosopher)
{
	return ((!is_state(philosopher, EATING) && get_time() > philosopher->limit)
		|| is_state(philosopher, DEAD));
}

int	is_full(t_philosopher *philosopher)
{
	return (philosopher->settings.must_eat_time > 0
		&& philosopher->meals >= philosopher->settings.must_eat_time);
}

int	everyone_is_full(t_app *app)
{
	size_t	i;
	size_t	full;

	i = -1;
	full = 0;
	while (app->philosophers[++i])
	{
		if (is_full(app->philosophers[i]))
			full++;
	}
	return (full == app->settings.philosophers);
}

int	anyone_dead(t_app *app)
{
	size_t	i;

	i = -1;
	while (app->philosophers[++i])
	{
		if (should_be_dead(app->philosophers[i]))
			return (1);
	}
	return (0);
}
