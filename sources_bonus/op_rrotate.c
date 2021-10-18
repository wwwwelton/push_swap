/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 15:33:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_rrotate(int **stack, int *size)
{
	int	tmp;

	if (*size >= 1)
	{
		tmp = (*stack)[*size - 1];
		ft_memmove(&(*stack)[1], &(*stack)[0], sizeof(int) * *size);
		(*stack)[0] = tmp;
	}
}

void	rrotate(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	if (stack_a && !stack_b)
		do_rrotate(stack_a, size_a);
	else if (!stack_a && stack_b)
		do_rrotate(stack_b, size_b);
	else if (stack_a && stack_b)
	{
		do_rrotate(stack_a, size_a);
		do_rrotate(stack_b, size_b);
	}
}
