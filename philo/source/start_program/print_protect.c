/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_protect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/23 17:44:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	print_protect(t_philo *philo, char *msg)
{
	t_bool		status;

	pthread_mutex_lock(philo->protection);
	status = *philo->die_table == FALSE;
	if (status == TRUE)
		printf("%d %d %s\n", get_time(), philo->position, msg);
	pthread_mutex_unlock(philo->protection);
	return (status);
}
