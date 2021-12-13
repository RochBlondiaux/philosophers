/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 18:53:03 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	bring_them_to_life(t_app app)
{
	int	i;

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
	set_state(philosopher, EATING);
	pthread_exit(EXIT_SUCCESS);
}
