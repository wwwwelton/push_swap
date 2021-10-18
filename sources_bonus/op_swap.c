/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 14:14:27 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_swap(int **stack, int *size)
{
	int	tmp;

	if (*size >= 1)
	{
		tmp = (*stack)[0];
		(*stack)[0] = (*stack)[1];
		(*stack)[1] = tmp;
	}
}

void	swap(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	if (stack_a && !stack_b)
		do_swap(stack_a, size_a);
	else if (!stack_a && stack_b)
		do_swap(stack_b, size_b);
	else if (stack_a && stack_b)
	{
		do_swap(stack_a, size_a);
		do_swap(stack_b, size_b);
	}
}
