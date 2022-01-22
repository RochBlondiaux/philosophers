/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:49:10 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 16:12:50 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex);
	philosopher->limit = get_time() + philosopher->settings.time_to_die;
	usleep(get_waiting_time(philosopher, EATING));
	pthread_mutex_unlock(&philosopher->eat_mutex);
	pthread_mutex_unlock(&philosopher->mutex);
}
