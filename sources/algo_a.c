/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 22:37:22 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo_a(t_data *data)
{
	t_algo	*algo;

	algo = data->algo_a;
	init_stack(algo->stack_a, data->args, data->args_size);
	if (!valid_sort(algo))
	{
		do_op(PA, algo);
		do_op(RRA, algo);
		do_op(RA, algo);
	}
}
