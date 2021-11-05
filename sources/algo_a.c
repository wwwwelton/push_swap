/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 01:01:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pre_sort(t_algo *algo, t_data *data, int smallest, int biggest)
{
	algo->op_count = 0;
	while (algo->stack_a->size > data->args_size / 2)
	{
		if (algo->stack_a->items[0] == smallest
			|| algo->stack_a->items[0] == biggest)
			do_op(RA, algo);
		else if (algo->stack_a->items[0] < (data->args_size / 2) + 1)
			do_op(PB, algo);
		else
			do_op(RA, algo);
	}
	while (!stack_is_sorted(algo->stack_a))
	{
		if (algo->stack_a->items[0] == smallest
			|| algo->stack_a->items[0] == biggest)
			do_op(RA, algo);
		else
			do_op(PB, algo);
	}
}

void	sort_algo_a(t_data *data)
{
	int		smallest;
	int		biggest;
	t_algo	*algo;

	algo = data->algo_a;
	init_stack(algo->stack_a, data->args, data->args_size);
	normalize(algo->stack_a->items, algo->stack_a->size);
	smallest = get_smallest_nbr(algo->stack_a->items, algo->stack_a->size);
	biggest = get_biggest_nbr(algo->stack_a->items, algo->stack_a->size);
	if (!valid_sort(algo))
	{
		pre_sort(algo, data, smallest, biggest);
		while (!stack_is_empty(algo->stack_b))
		{
			go_to_best_comb(algo->stack_a, algo->stack_b, data);
			if (algo->stack_a->items[0] < algo->stack_b->items[0])
			{
				do_op(RA, algo);
				do_op(PA, algo);
			}
			else
				do_op(PA, algo);
		}
		go_to(algo->stack_a, algo, smallest, 'a');
	}
}
