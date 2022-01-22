/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:22:40 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/22 14:38:22 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t) 1000) + (time.tv_usec / 1000));
}

int	should_be_dead(t_philosopher *philosopher)
{
	return (!is_state(philosopher, EATING) && get_time() > philosopher->limit);
}
