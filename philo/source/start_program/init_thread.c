/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/26 11:30:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		ft_putstr_err("Error creating thread\n");
}

void	start_routine(t_table *table, int n_thread)
{
	int		index;

	index = -1;
	init_th(&table->threads[n_thread], &guardian, &table->guardian);
	while (++index < n_thread)
		init_th(&table->threads[index], &routine, &table->philos[index]);
}

int	wait_routine(t_table *table, int n_thread)
{
	int		index;
	int		status;

	status = 0;
	index = -1;
	while (++index < n_thread)
		pthread_join(table->threads[index], NULL);
	if (table->die == TRUE)
		status = 1;
	pthread_mutex_lock(&table->die_protection);
	table->die = TRUE;
	pthread_mutex_unlock(&table->die_protection);
	pthread_join(table->threads[index], NULL);
	return (status);
}

void	init_threads(t_table *table, int n_thread)
{
	start_routine(table, n_thread);
	wait_routine(table, n_thread);
}
