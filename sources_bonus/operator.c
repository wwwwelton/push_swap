/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/20 09:27:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	op_to_code(char *op)
{
	int	i;

	i = 0;
	i += *op;
	while (*op)
		i += *op++;
	return (i);
}

static void	set_op(int op, t_data *data)
{
	if (op == SA || op == SB || op == SS)
		swap(op, data);
	else if (op == PA || op == PB)
		push(op, data);
	else if (op == RA || op == RB || op == RR)
		rotate(op, data);
	else if (op == RRA || op == RRB || op == RRR)
		rrotate(op, data);
}

void	set_ops(t_data *data)
{
	int		i;
	char	**operations;

	operations = ft_split(data->operations, ' ');
	if (!operations)
		exit_error("Failed to split operations\n", 1, data);
	i = -1;
	while (operations[++i])
		set_op(op_to_code(operations[i]), data);
	free_splited_mat(operations);
}
