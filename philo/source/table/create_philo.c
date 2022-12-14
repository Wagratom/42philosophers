/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:00:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 11:52:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	*create_philo(char *argv[], t_table *table, int index)
{
	t_philo			new_philo;
	static int		position = 0;

	if (index == -1)
		return (&position);
	position++;
	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.position = position;
	new_philo.fork1 = &table->forks[index];
	new_philo.fork2 = &table->forks[index + 1];
	new_philo.die_table = &table->die;
	new_philo.protection = &table->print_protection;
	new_philo.die_protection = &table->die_protection;
	table->philos[index] = new_philo;
	return (&position);
}

void	create_last_philo(char *argv[], t_table *table, int position)
{
	t_philo		new_philo;

	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.position = position + 1;
	new_philo.die_table = &table->die;
	new_philo.protection = &table->print_protection;
	new_philo.die_protection = &table->die_protection;
	table->philos[position] = new_philo;
}

void	create_philos(t_table *table, int size, char *argv[])
{
	int		index;

	table->philos = (t_philo *)ft_calloc(sizeof(t_philo), size);
	index = -1;
	while (++index < size - 1)
		create_philo(argv, table, index);
	create_last_philo(argv, table, index);
	table->philos[index].fork1 = &table->forks[index];
	table->philos[index].fork2 = &table->forks[0];
}
