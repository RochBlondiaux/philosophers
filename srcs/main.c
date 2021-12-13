/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:25:21 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 18:44:24 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_app	app;

	parse_settings(&app.settings, argc, argv);
	if (!validate_settings(app.settings))
		return (EXIT_FAILURE);
	create_philosophers(&app);
	if (!app.philosophers)
		return (EXIT_FAILURE);
	if (!app.forks)
	{
		if (app.philosophers)
			clear_philosophers(&app);
		return (EXIT_FAILURE);
	}
	bring_them_to_life(app);
	clear_philosophers(&app);
	return (EXIT_SUCCESS);
}
