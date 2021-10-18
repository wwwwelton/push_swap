/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 15:07:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_rotate(int **stack, int *size)
{
	int	tmp;

	if (*size >= 1)
	{
		tmp = (*stack)[0];
		ft_memmove(&(*stack)[0], &(*stack)[1], sizeof(int) * *size);
		(*stack)[*size - 1] = tmp;
	}
}

void	rotate(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	if (stack_a && !stack_b)
		do_rotate(stack_a, size_a);
	else if (!stack_a && stack_b)
		do_rotate(stack_b, size_b);
	else if (stack_a && stack_b)
	{
		do_rotate(stack_a, size_a);
		do_rotate(stack_b, size_b);
	}
}
