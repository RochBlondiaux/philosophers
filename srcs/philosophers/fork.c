/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:43 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/15 11:53:29 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_fork_available(t_app *app, int id)
{
	int	i;

	i = 0;
	while (app->philosophers[i])
	{
		if (app->philosophers[i]->left_fork == id
			|| app->philosophers[i]->right_fork == id)
			return (0);
		i++;
	}
	return (1);
}

int	get_available_forks(t_app *app)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (app->forks[index])
	{
		if (is_fork_available(app, index))
			i++;
		index++;
	}
	return (i);
}

int	get_fork(t_app *app)
{
	size_t	index;

	index = 0;
	while (app->forks[index])
	{
		if (is_fork_available(app, index))
			return (index);
		index++;
	}
	return (-1);
}
