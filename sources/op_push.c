/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 10:51:50 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_push(
	int *stack_from, int *size_from, int *stack_to, int *size_to)
{
	if (*size_from >= 1)
	{
		ft_memmove(&stack_to[1], &stack_to[0], sizeof(int) * *size_to);
		stack_to[0] = stack_from[0];
		(*size_to)++;
		(*size_from)--;
		ft_memmove(&stack_from[0], &stack_from[1], sizeof(int) * *size_from);
	}
}

void	push(int op, t_algo *algo)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = algo->stack_a;
	stack_b = algo->stack_b;
	if (op == PA)
		do_push(stack_b->items, &stack_b->top, stack_a->items, &stack_a->top);
	else if (op == PB)
		do_push(stack_a->items, &stack_a->top, stack_b->items, &stack_b->top);
}
