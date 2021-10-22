/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 13:44:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_op(int op, t_algo *algo)
{
	char	*opt;

	opt = code_to_op(op, algo->options);
	algo->operations = ft_strmerge(algo->operations, opt);
	algo->op_count++;
}

static void	set_op(int op, t_algo *algo)
{
	if (op == SA || op == SB || op == SS)
		swap(op, algo);
	else if (op == PA || op == PB)
		push(op, algo);
	else if (op == RA || op == RB || op == RR)
		rotate(op, algo);
	else if (op == RRA || op == RRB || op == RRR)
		rrotate(op, algo);
}

void	do_op(int op, t_algo *algo)
{
	set_op(op, algo);
	save_op(op, algo);
}
