/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 04:33:29 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->stack_a = (int *)new_array(sizeof(int *), argc - 1);
	data->stack_b = (int *)new_array(sizeof(int *), argc - 1);
	if (data->stack_a == NULL || data->stack_b == NULL)
		exit_error(data);
	data->stack_size = argc - 1;
	data->ops = NULL;
	data->ops_count = 0;
	data->stack_ordered = false;
	data->argc = argc;
	data->argv = argv;
}

void	deinit_data(t_data *data)
{
	ft_free_ptr((void *)&data->stack_a);
	ft_free_ptr((void *)&data->stack_b);
}
