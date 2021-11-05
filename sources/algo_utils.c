/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/04 22:51:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int *items, int size)
{
	ft_memcpy(stack->items, items, sizeof(int) * size);
	stack->size = size;
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	stack_is_sorted(t_stack *stack)
{
	return (is_sorted(stack->items, stack->size));
}

int	valid_sort(t_algo *algo)
{
	if (stack_is_sorted(algo->stack_a) && stack_is_empty(algo->stack_b))
		return (true);
	return (false);
}
