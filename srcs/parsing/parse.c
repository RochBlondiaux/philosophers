/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:45:39 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/24 10:04:28 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	validate_settings(t_settings settings)
{
	if (settings.return_code == 0)
		return (1);
	else if (settings.return_code == TOO_MANY_ARGUMENTS)
		printf("%s %s\n", TOO_MANY_ARGUMENTS_MSG, USAGE);
	else if (settings.return_code == MISSING_ARGUMENTS)
		printf("%s %s\n", MISSING_ARGUMENTS_MSG, USAGE);
	else if (settings.return_code == WRONG_ARGUMENT_TYPE)
		printf("%s %s\n", WRONG_ARGUMENT_TYPE_MSG, USAGE);
	return (0);
}

static void	set_setting(t_settings *settings, int key, int value)
{
	if (key == 1)
		settings->philosophers = value;
	else if (key == 2)
		settings->time_to_die = value;
	else if (key == 3)
		settings->time_to_eat = value;
	else if (key == 4)
		settings->time_to_sleep = value;
	else if (key == 5)
		settings->must_eat_time = value;
}

void	parse_settings(t_settings *settings, int argc, char **argv)
{
	size_t	i;

	if (argc < 5)
		settings->return_code = MISSING_ARGUMENTS;
	else if (argc > 6)
		settings->return_code = TOO_MANY_ARGUMENTS;
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!is_number(argv[i]))
			{
				settings->return_code = WRONG_ARGUMENT_TYPE;
				return ;
			}
			set_setting(settings, i, ft_atoi(argv[i]));
			i++;
		}
		if (i < 6)
			set_setting(settings, 5, -1);
		settings->return_code = 0;
	}
}
