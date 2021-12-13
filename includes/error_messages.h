/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:47:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 17:33:06 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/**
 * Parsing errors
 */
# define USAGE "Usage: ./philo <count> <die> <eat> <sleep> [number_of_times_each_philosopher_must_eat]"
# define MISSING_ARGUMENTS_MSG "Missing arguments!"
# define TOO_MANY_ARGUMENTS_MSG "Too many arguments!"
# define WRONG_ARGUMENT_TYPE_MSG "Wrong argument type!"
# define EAGAIN_MSG "Cannot create new thread: max thread numbers reached!\n"
# define EINVAL_MSG "Cannot create new thread: invalid arguments!\n"
# define EPERM_MSG "Cannot create new thread: wrong permissions!\n"

#endif