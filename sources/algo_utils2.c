/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 14:33:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves(t_stack *stack, int n)
{
	int	index;

	index = get_index(stack->items, stack->size, n);
	if (index <= stack->size / 2 || index == INT_MAX)
		return (index);
	else
		return ((stack->size + 1) - index);
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

int	put_nbr_to_index(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (!(n > array[i] && n < array[i + 1]) && i < (size - 2))
		i++;
	return (i + 1);
}

void	normalize(int *array, int size)
{
	int	i;
	int	*tmp_array;

	tmp_array = (int *)malloc(sizeof(int) * size);
	if (!tmp_array)
		return ;
	ft_memcpy(tmp_array, array, sizeof(int) * size);
	bubble_sort(tmp_array, size);
	i = -1;
	while (++i < size)
		array[i] = get_index(tmp_array, size, array[i]);
	ft_free_ptr((void *)&tmp_array);
}

void	go_to_best_comb(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int	index;
	int	moves;
	int	tmp_a;
	int	tmp_b;
	int	i;

	index = 0;
	i = -1;
	moves = data->args_size - 1;
	while (++i < stack_b->size)
	{
		tmp_b = stack_b->items[i];
		index = put_nbr_to_index(stack_a->items, stack_a->size, tmp_b);
		tmp_a = stack_a->items[index];
		if (get_moves(stack_a, tmp_a) + get_moves(stack_b, tmp_b) < moves)
		{
			stack_a->top = tmp_a;
			stack_b->top = tmp_b;
			moves = get_moves(stack_a, tmp_a) + get_moves(stack_b, tmp_b);
		}
	}
	go_to(stack_a, data->algo_a, stack_a->top, 'a');
	go_to(stack_b, data->algo_a, stack_b->top, 'b');
}
