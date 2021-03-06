/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 04:21:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_algo_failed(t_algo *algo)
{
	if (!algo->operations
		|| !algo->options
		|| !algo->stack_a->items
		|| !algo->stack_b->items)
		return (TRUE);
	return (FALSE);
}

static int	init_data_failed(t_data *data)
{
	if (!data->args
		|| init_algo_failed(data->algo_a)
		|| init_algo_failed(data->algo_b))
		return (TRUE);
	return (FALSE);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->algo_a = new_algo(argc - 1);
	data->algo_b = new_algo(argc - 1);
	data->args = (int *)new_array(sizeof(int), argc - 1);
	if (init_data_failed(data))
		exit_error("Memory allocation failed\n", 1, data);
	data->args_size = argc - 1;
	data->argc = argc;
	data->argv = argv;
}

static void	deinit_algo(t_algo *algo)
{
	ft_free_ptr((void *)&algo->stack_a->items);
	ft_free_ptr((void *)&algo->stack_b->items);
	ft_free_ptr((void *)&algo->stack_a);
	ft_free_ptr((void *)&algo->stack_b);
	ft_free_ptr((void *)&algo->operations);
	free_splited_mat(algo->options);
	ft_free_ptr((void *)&algo);
}

void	deinit_data(t_data *data)
{
	deinit_algo(data->algo_a);
	deinit_algo(data->algo_b);
	ft_free_ptr((void *)&data->args);
}
