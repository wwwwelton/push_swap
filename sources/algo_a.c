/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 15:31:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo_a(t_data *data)
{
	t_algo	*algo;

	algo = data->algo_a;
	ft_memcpy(algo->stack_a->items, data->args, sizeof(int) * data->args_size);
	do_op(PA, algo);
	do_op(PB, algo);
}
