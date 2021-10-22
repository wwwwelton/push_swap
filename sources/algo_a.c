/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 06:31:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo_a(t_data *data)
{
	t_algo	*algo;

	algo = data->algo_a;
	algo->op_count = 2;
	algo->operations = ft_strmerge(algo->operations, ft_strdup("ra"));
	algo->operations = ft_strmerge(algo->operations, ft_strdup(" "));
	algo->operations = ft_strmerge(algo->operations, ft_strdup("rra"));
	algo->operations = ft_strmerge(algo->operations, ft_strdup(" "));
	ft_memcpy(algo->stack_a, data->args, data->args_size);
}
