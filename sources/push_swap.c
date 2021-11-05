/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 03:17:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	get_args(&data);
	if (!is_sorted(data.args, data.args_size))
	{
		if (data.args_size >= 10)
			sort_algo_a(&data);
		else
			sort_algo_b(&data);
		print_best_algo(&data);
	}
	deinit_data(&data);
	return (EXIT_SUCCESS);
}
