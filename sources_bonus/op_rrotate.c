/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/19 00:12:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_rrotate(int *stack, int size)
{
	int	tmp;

	if (size >= 1)
	{
		tmp = stack[size - 1];
		ft_memmove(&stack[1], &stack[0], sizeof(int) * size);
		stack[0] = tmp;
	}
}

void	rrotate(int op, t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (op == RA)
		do_rrotate(stack_a->items, stack_a->top);
	else if (op == RB)
		do_rrotate(stack_b->items, stack_b->top);
	else if (op == RR)
	{
		do_rrotate(stack_a->items, stack_a->top);
		do_rrotate(stack_b->items, stack_b->top);
	}
}
