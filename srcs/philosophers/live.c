/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 16:12:50 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*live(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	while (1)
	{
		if (should_be_dead(philosopher)) {
			set_state(philosopher, DEAD);
			break ;
		}
		take_forks(philosopher);
		set_state(philosopher, EATING);
		philosopher->limit = get_time() + philosopher->settings.time_to_die;
		usleep(get_waiting_time(philosopher, EATING));
		philosopher->meals++;
		clear_forks(philosopher);
	}
	return (NULL);
}
