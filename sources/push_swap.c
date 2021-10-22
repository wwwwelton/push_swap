/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 06:57:12 by wleite           ###   ########.fr       */
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
		sort_algo_a(&data);
		sort_algo_b(&data);
	}
	deinit_data(&data);
	return (EXIT_SUCCESS);
}
