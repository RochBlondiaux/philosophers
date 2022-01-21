/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:54:01 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/21 21:22:19 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	clear_forks_(t_app *app)
{
	size_t	i;

	if (!app->forks)
		return ;
	while (app->forks[i])
	{
		pthread_mutex_destroy(app->forks[i]);
		i++;
	}
	free(app->forks);
}

void	clear_philosophers(t_app *app)
{
	size_t	i;

	if (!app)
		return ;
	i = 0;
	if (app->philosophers)
	{
		while (app->philosophers[i])
		{
			pthread_mutex_destroy(app->philosophers[i]->mutex);
			pthread_mutex_destroy(app->philosophers[i]->eat_mutex);
			free(app->philosophers[i]);
			i++;
		}
		free(app->philosophers);
	}
	clear_forks_(app);
}
