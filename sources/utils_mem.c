/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/20 21:50:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*new_array(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(number * size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

t_stack	*new_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->maxsize = capacity;
	stack->top = 0;
	stack->items = (int *)new_array(sizeof(int *), capacity);
	return (stack);
}

t_algo	*new_algo(int capacity)
{
	t_algo	*algo;

	algo = (t_algo *)malloc(sizeof(t_algo));
	if (!algo)
		return (NULL);
	algo->stack_a = new_stack(capacity);
	algo->stack_b = new_stack(capacity);
	algo->operations = ft_strdup("");
	algo->op_count = 0;
	return (algo);
}
