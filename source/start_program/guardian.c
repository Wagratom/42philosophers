/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 11:53:15 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print_protect_guardian(t_guardian *guardian, int index)
{
	pthread_mutex_lock(guardian->print_protection);
	printf("%d %d died\n", get_time(), index);
	*guardian->die_table = TRUE;
	pthread_mutex_unlock(guardian->print_protection);
}

static void	verify_die(t_guardian *guardian)
{
	int	index;

	index = -1;
	while (++index < guardian->size)
	{
		pthread_mutex_lock(guardian->die_protection);
		if (get_time() > *guardian->die_philos[index])
		{
			print_protect_guardian(guardian, (index + 1));
			pthread_mutex_unlock(guardian->die_protection);
			return ;
		}
		pthread_mutex_unlock(guardian->die_protection);
	}
}

void	*guardian(void *argument)
{
	t_guardian	*guardian;

	guardian = (t_guardian *)argument;
	while (*guardian->die_table == FALSE)
		verify_die(guardian);
	return (NULL);
}
