/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 18:18:32 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	set_state(t_app app, t_philosopher *philosopher, t_philosopher_state state)
{
	char	*format;

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
	printf(format, app.start_time.tv_usec, philosopher->index);
}

int	is_state(t_philosopher *philosopher, t_philosopher_state state)
{
	return (philosopher->state == state);
}
