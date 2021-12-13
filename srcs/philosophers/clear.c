/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:54:01 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 17:56:29 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	clear_philosophers(t_app *app)
{
	size_t	i;

	if (!app || !app->philosophers)
		return ;
	i = 0;
	while (app->philosophers[i])
	{
		free(app->philosophers[i]);
		i++;
	}
	free(app->philosophers);
}
