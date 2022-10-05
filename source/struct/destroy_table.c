/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:07:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/05 14:05:20 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	destroy_table(int status)
{
	int index;
	int	nbr_philo;
	pthread_mutex_t	*aux;

	index = -1;
	nbr_philo = table()->nbr_philo;
	aux = table()->forks;
	while(++index < nbr_philo)
		pthread_mutex_destroy(&aux[index]);
	free(table()->forks);
	free(table()->threads);
	free(table()->philos);
	exit(status);
}