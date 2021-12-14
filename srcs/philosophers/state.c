/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/14 17:20:14 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_anybody_dead(t_philosopher *philosopher)
{
	t_philosopher	*tmp;

	tmp = philosopher->previous;
	while (tmp && tmp->index != philosopher->index)
	{
		if (is_state(tmp, DEAD))
			return (1);
		tmp = philosopher->previous;
	}
	return (0);
}

static useconds_t	get_waiting_time(t_philosopher *philosopher,
							t_philosopher_state state)
{
	t_settings	settings;
	useconds_t	time;

	settings = philosopher->settings;
	if (state == SLEEPING)
		time = settings.time_to_sleep;
	else if (state == EATING)
		time = settings.time_to_eat;
	else
		time = 0;
	return (time * 1000);
}

useconds_t	set_state(t_philosopher *philosopher, t_philosopher_state state)
{
	char			*format;
	struct timeval	time;

	if (philosopher->state == state)
		return (0);
	philosopher->state = state;
	if (state == EATING)
		format = EATING_MSG;
	else if (state == SLEEPING)
		format = SLEEPING_MSG;
	else if (state == THINKING)
		format = THINKING_MSG;
	else if (state == DEAD)
		format = DIED_MSG;
	else if (state == TAKING_FORK)
		format = FORK_MSG;
	gettimeofday(&time, NULL);
	printf(format, time.tv_usec, philosopher->index);
	return (get_waiting_time(philosopher, state));
}

int	is_state(t_philosopher *philosopher, t_philosopher_state state)
{
	return (philosopher->state == state);
}
