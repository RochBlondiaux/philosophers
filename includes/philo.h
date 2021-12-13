/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:23:44 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 18:51:40 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 * Includes
 */
# include "error_messages.h"
# include "error_codes.h"
# include "messages.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <errno.h>

/**
 * Enumerations
 */
typedef enum e_philosopher_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_philosopher_state;

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

typedef struct s_philosopher
{
	int					index;
	t_philosopher_state	state;
	pthread_t			thread;
}		t_philosopher;

typedef struct s_app
{
	t_settings		settings;
	t_philosopher	**philosophers;
}					t_app;

/**
 * Parsing
 */
void	parse_settings(t_settings *settings, int argc, char **argv);
int		validate_settings(t_settings settings);

/**
 * Philosophers
 */
void	create_philosophers(t_app *app);
void	clear_philosophers(t_app *app);
int		is_state(t_philosopher *philosopher, t_philosopher_state state);
void	set_state(t_philosopher *philosopher, t_philosopher_state state);
void	*live(void *philosopher);
void	bring_them_to_life(t_app app);

/**
 * Threads
 */
int		validate_thread(int code);

/**
 * Utils
 */
int		is_number(char *a);
int		ft_atoi(char *str);

#endif