/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 03:49:46 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_short(t_algo *algo, int smallest, int biggest)
{
	while (!valid_sort(algo))
	{
		if (algo->stack_a->items[0] == biggest)
			do_op(RA, algo);
		else if (algo->stack_a->items[1] == smallest)
			do_op(SA, algo);
		else
			do_op(RRA, algo);
	}
}

static void	sort_long(t_algo *algo, int smallest, int biggest)
{
	while (algo->stack_a->size > 2)
	{
		if (algo->stack_a->items[0] == smallest
			|| algo->stack_a->items[0] == biggest)
			do_op(RA, algo);
		else
			do_op(PB, algo);
	}
	while (!stack_is_empty(algo->stack_b))
	{
		biggest = get_biggest_nbr(algo->stack_b->items,
				algo->stack_b->size);
		go_to(algo->stack_b, algo, biggest, 'b');
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

void	sort_algo_b(t_data *data)
{
	int		smallest;
	int		biggest;
	t_algo	*algo;

	algo = data->algo_b;
	algo->op_count = 0;
	init_stack(algo->stack_a, data->args, data->args_size);
	normalize(algo->stack_a->items, algo->stack_a->size);
	smallest = get_smallest_nbr(algo->stack_a->items, algo->stack_a->size);
	biggest = get_biggest_nbr(algo->stack_a->items, algo->stack_a->size);
	if (!valid_sort(algo))
	{
		if (data->args_size <= 3)
			sort_short(algo, smallest, biggest);
		else
			sort_long(algo, smallest, biggest);
	}
}
