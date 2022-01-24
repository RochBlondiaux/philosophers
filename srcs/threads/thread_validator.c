/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:29:16 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/24 10:04:28 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	validate_thread(int code)
{
	if (code == 0)
		return (1);
	else if (code == EAGAIN)
		printf(EAGAIN_MSG);
	else if (code == EINVAL)
		printf(EINVAL_MSG);
	else if (code == EPERM)
		printf(EPERM_MSG);
	return (0);
}
