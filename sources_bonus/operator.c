/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 15:28:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	set_op(char *op, t_data *data)
{
	if (!ft_strncmp(op, "sa", 3))
		swap(&data->stack_a, &data->size_a, NULL, 0);
	else if (!ft_strncmp(op, "sb", 3))
		swap(NULL, 0, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "ss", 3))
		swap(&data->stack_a, &data->size_a, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "pa", 3))
		push(&data->stack_b, &data->size_b, &data->stack_a, &data->size_a);
	else if (!ft_strncmp(op, "pb", 3))
		push(&data->stack_a, &data->size_a, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "ra", 3))
		rotate(&data->stack_a, &data->size_a, NULL, 0);
	else if (!ft_strncmp(op, "rb", 3))
		rotate(NULL, 0, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "rr", 3))
		rotate(&data->stack_a, &data->size_a, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "rra", 4))
		rrotate(&data->stack_a, &data->size_a, NULL, 0);
	else if (!ft_strncmp(op, "rrb", 4))
		rrotate(NULL, 0, &data->stack_b, &data->size_b);
	else if (!ft_strncmp(op, "rrr", 4))
		rrotate(&data->stack_a, &data->size_a, &data->stack_b, &data->size_b);
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
		set_op(operations[i], data);
	free_splited_mat(operations);
}