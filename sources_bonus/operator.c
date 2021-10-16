/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 15:09:53 by wleite           ###   ########.fr       */
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
