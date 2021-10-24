/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/24 09:29:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrotate(int *stack, int size)
{
	int	tmp;

	if (size >= 1)
	{
		tmp = stack[size - 1];
		ft_memmove(&stack[1], &stack[0], sizeof(int) * (size - 1));
		stack[0] = tmp;
	}
}

void	rrotate(int op, t_algo *algo)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = algo->stack_a;
	stack_b = algo->stack_b;
	if (op == RRA)
		do_rrotate(stack_a->items, stack_a->size);
	else if (op == RRB)
		do_rrotate(stack_b->items, stack_b->size);
	else if (op == RRR)
	{
		do_rrotate(stack_a->items, stack_a->size);
		do_rrotate(stack_b->items, stack_b->size);
	}
}
