/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 06:35:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operations(char *operations)
{
	int		i;
	char	**splited_operations;

	splited_operations = ft_split(operations, ' ');
	i = -1;
	while (splited_operations[++i])
	{
		ft_putstr_fd(splited_operations[i], 1);
		ft_putstr_fd("\n", 1);
	}
	free_splited_mat(splited_operations);
}

void	print_best_algo(t_data *data)
{
	if (data->algo_a <= data->algo_b)
		print_operations(data->algo_a->operations);
	else
		print_operations(data->algo_b->operations);
}
