/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 10:59:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(int *stack, int size)
{
	int	tmp;

	if (size >= 1)
	{
		tmp = stack[0];
		ft_memmove(&stack[0], &stack[1], sizeof(int) * (size - 1));
		stack[size - 1] = tmp;
	}
}

void	rotate(int op, t_algo *algo)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = algo->stack_a;
	stack_b = algo->stack_b;
	if (op == RA)
		do_rotate(stack_a->items, stack_a->top);
	else if (op == RB)
		do_rotate(stack_b->items, stack_b->top);
	else if (op == RR)
	{
		do_rotate(stack_a->items, stack_a->top);
		do_rotate(stack_b->items, stack_b->top);
	}
}
