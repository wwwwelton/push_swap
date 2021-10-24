/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_op_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/24 09:41:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	do_swap(int *stack, int size)
{
	int	tmp;

	if (size >= 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	swap(int op, t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (op == SA)
		do_swap(stack_a->items, stack_a->size);
	else if (op == SB)
		do_swap(stack_b->items, stack_b->size);
	else if (op == SS)
	{
		do_swap(stack_a->items, stack_a->size);
		do_swap(stack_b->items, stack_b->size);
	}
}
