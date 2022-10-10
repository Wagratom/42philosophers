/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 13:33:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minunit.h"
# include "../include/philosophers.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(basic_tst)
{
	t_table table;

	creat_table(&table, (char *[]){"a.out", "2", "3", "1", "2", "5", NULL});
	init_ths(&table);
}

MU_TEST(medio_tst)
{
	t_table table;

	creat_table(&table, (char *[]){"a.out", "4", "500", "200", "200", "5", NULL});
	init_ths(&table);
}

MU_TEST(death_basic_tft)
{
	t_table table;

	creat_table(&table, (char *[]){"a.out", "4", "400", "500", "200", "4", NULL});
	init_ths(&table);
}


MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(basic_tst);
	//MU_RUN_TEST(medio_tst);
	//MU_RUN_TEST(death_basic_tft);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
