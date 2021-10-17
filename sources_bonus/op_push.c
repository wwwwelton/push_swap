/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/17 01:42:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_push(int **stk_from, int *size_from, int **stk_to, int *size_to)
{
	if (*size_from >= 1)
	{
		(*stk_to)[*size_to] = (*stk_from)[*size_from - 1];
		(*size_to)++;
		(*size_from)--;
	}
}

void	push(int **stack_from, int *size_from, int **stack_to, int *size_to)
{
	do_push(stack_from, size_from, stack_to, size_to);
}
