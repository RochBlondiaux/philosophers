/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 18:01:58 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philosopher	*create_philosopher(int index)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof (t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->index = index;
	philosopher->state = THINKING;
	return (philosopher);
}

void	create_philosophers(t_app *app)
{
	size_t			i;
	t_philosopher	*new;

	app->philosophers = malloc(sizeof (t_philosopher)
			* (app->settings.philosophers + 1));
	if (!app->philosophers)
	{
		app->philosophers = NULL;
		return ;
	}
	i = 1;
	while (i <= app->settings.philosophers)
	{
		new = create_philosopher(i);
		if (!new)
		{
			clear_philosophers(app);
			break;
		}
		app->philosophers[i - 1] = new;
		i++;
	}
	app->philosophers[i - 1] = NULL;
}
