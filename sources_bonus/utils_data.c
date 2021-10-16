/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 14:01:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->stack_a = (int *)new_array(sizeof(int *), argc - 1);
	data->stack_b = (int *)new_array(sizeof(int *), argc - 1);
	data->options = ft_split(OPTIONS, ' ');
	data->operations = ft_strdup("");
	if (!data->stack_a || !data->stack_b || !data->operations || !data->options)
		exit_error("Memory allocation failed\n", 1, data);
	data->stack_size = argc - 1;
	data->size_a = argc - 1;
	data->size_b = 0;
	data->op_count = 0;
	data->stack_ordered = false;
	data->argc = argc;
	data->argv = argv;
}

void	deinit_data(t_data *data)
{
	ft_free_ptr((void *)&data->stack_a);
	ft_free_ptr((void *)&data->stack_b);
	ft_free_ptr((void *)&data->operations);
	free_splited_mat(data->options);
}
