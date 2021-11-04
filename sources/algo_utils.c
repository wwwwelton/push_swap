/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/04 01:58:53 by wleite           ###   ########.fr       */
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

void	go_to(t_stack *stack, t_algo *algo, int n, char id)
{
	int	index;
	int	len;

	index = get_index(stack->items, stack->size, n);
	len = stack->size - 1;
	if (index > -1)
	{
		if (len - index < index && id == 'a')
			while (stack->items[0] != n)
				do_op(RRA, algo);
		else if (len - index >= index && id == 'a')
			while (stack->items[0] != n)
				do_op(RA, algo);
		if (len - index < index && id == 'b')
			while (stack->items[0] != n)
				do_op(RRB, algo);
		else if (len - index >= index && id == 'b')
			while (stack->items[0] != n)
				do_op(RB, algo);
	}
}

int	get_moves(t_stack *stack, int n)
{
	int	index;

	index = get_index(stack->items, stack->size, n);
	if (index <= stack->size / 2 || index == INT_MAX)
		return (index);
	else
		return ((stack->size + 1) - index);
}

int	put_nbr_to_index(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (!(n > array[i] && n < array[i + 1]) && i < (size - 2))
		i++;
	return (i + 1);
}

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b, t_algo *algo, int	data_size)
{
	int	index;
	int	moves;
	int	tmp_a;
	int	tmp_b;
	int	a;
	int	b;
	int	tmp;

	index = 0;
	tmp = 0;
	moves = data_size - 1;
	while (tmp < stack_b->size)
	{
		tmp_b = stack_b->items[tmp];
		index = put_nbr_to_index(stack_a->items, stack_a->size, tmp_b);
		tmp_a = stack_a->items[index];
		if (get_moves(stack_a, tmp_a) + get_moves(stack_b, tmp_b) < moves)
		{
			a = tmp_a;
			b = tmp_b;
			moves = get_moves(stack_a, tmp_a) + get_moves(stack_b, tmp_b);
		}
		tmp++;
	}
	go_to(stack_a, algo, a, 'a');
	go_to(stack_b, algo, b, 'b');
}
