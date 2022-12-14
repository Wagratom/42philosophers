/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:39:31 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 10:52:27 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!valid_argv(argc, argv))
		return (1);
	create_table(&table, argv);
	handle_one_philo(&table, table.nbr_philo);
	init_threads(&table, table.nbr_philo);
	destroy_table(&table, table.nbr_philo);
	return (0);
}
