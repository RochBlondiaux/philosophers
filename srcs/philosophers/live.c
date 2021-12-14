/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/14 17:36:39 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	bring_them_to_life(t_app app)
{
	size_t	i;

	i = 0;
	while (app.philosophers[i])
	{
		pthread_join(app.philosophers[i]->thread, NULL);
		i++;
	}
}

void	*live(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	while (1)
	{
		if (is_state(philosopher->previous, EATING))
			usleep(set_state(philosopher, SLEEPING));
		else if (is_state(philosopher->previous, SLEEPING))
			usleep(set_state(philosopher, EATING));
	}
	return (NULL);
}
