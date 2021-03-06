/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:23:44 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/26 14:38:26 by rblondia         ###   ########.fr       */
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
	int		must_eat_time;
	int		return_code;
}			t_settings;

typedef struct s_philosopher
{
	int						index;
	t_philosopher_state		state;
	long long				limit;
	t_settings				settings;
	struct s_app			*app;
	int						right_fork;
	int						left_fork;
	pthread_t				thread;
	int						meals;
}							t_philosopher;

typedef struct s_app
{
	t_settings		settings;
	pthread_mutex_t	*forks;
	t_philosopher	**philosophers;
	pthread_mutex_t	somebody_dead;
	pthread_t		monitor;
}					t_app;

/**
 * Parsing
 */
void		parse_settings(t_settings *settings, int argc, char **argv);
int			validate_settings(t_settings settings);

/**
 * Philosophers
 */
void		create_philosophers(t_app *app);
void		clear_philosophers(t_app *app);
int			is_state(t_philosopher *philosopher, t_philosopher_state state);
void		set_state(t_philosopher *philosopher, t_philosopher_state state);
void		eat(t_philosopher *philosopher);

/*
 * Threads
 */
void		*live(void *philosopher);
void		*monitor(void *arg);

/* Fork */
void		take_forks(t_philosopher *philosopher);
void		clear_forks(t_philosopher *philosopher);

/**
 * Threads
 */
int			validate_thread(int code);

/**
 * Utils
 */
int			is_number(char *a);
int			ft_atoi(char *str);
long long	get_time(void);
useconds_t	get_waiting_time(t_philosopher *philosopher,
				t_philosopher_state state);
int			should_be_dead(t_philosopher *philosopher);
void		start(t_app *app);
void		init(t_philosopher *philosopher);
void		*eat_monitor(void *arg);
int			is_full(t_philosopher *philosopher);
int			everyone_is_full(t_app *app);
int			anyone_dead(t_app *app);

#endif