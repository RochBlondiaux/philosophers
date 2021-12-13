/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:23:44 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 17:08:44 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 * Includes
 */
# include "error_messages.h"
# include "error_codes.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

/**
 * Structures
 */
typedef struct s_settings
{
	size_t	philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	must_eat_time;
	int		return_code;
}			t_settings;

typedef struct s_app
{
	t_settings	settings;
}				t_app;

/**
 * Parsing
 */
void	parse_settings(t_settings *settings, int argc, char **argv);
int		validate_settings(t_settings settings);

/**
 * Utils
 */
int		is_number(char *a);
int		ft_atoi(char *str);

#endif