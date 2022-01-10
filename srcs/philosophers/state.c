/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/15 12:00:25 by rblondia         ###   ########.fr       */
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
		tmp = tmp->previous;
	}
	return (0);
}

useconds_t	get_waiting_time(t_philosopher *philosopher,
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

void	set_state(t_philosopher *philosopher, t_philosopher_state state)
{
	char			*format;

	if (philosopher->state == state)
		return ;
	philosopher->state = state;
	if (state == EATING)
	{
		philosopher->last_meal = get_time();
		format = EATING_MSG;
	}
	else if (state == SLEEPING)
	{
		philosopher->last_nap = get_time();
		format = SLEEPING_MSG;
	}
	else if (state == THINKING)
		format = THINKING_MSG;
	else if (state == DEAD)
		format = DIED_MSG;
	else if (state == TAKING_FORK)
		format = FORK_MSG;
	printf(format, get_time(), philosopher->index);
}

int	is_state(t_philosopher *philosopher, t_philosopher_state state)
{
	return (philosopher->state == state);
}
