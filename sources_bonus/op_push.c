/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 14:36:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_push(int **stk_from, int *size_from, int **stk_to, int *size_to)
{
	if (*size_from >= 1)
	{
		ft_memmove(&(*stk_to)[1], &(*stk_to)[0], sizeof(int) * *size_to);
		(*stk_to)[0] = (*stk_from)[0];
		(*size_to)++;
		(*size_from)--;
		ft_memmove(&(*stk_from)[0], &(*stk_from)[1], sizeof(int) * *size_from);
	}
}

void	push(int **stack_from, int *size_from, int **stack_to, int *size_to)
{
	do_push(stack_from, size_from, stack_to, size_to);
}
