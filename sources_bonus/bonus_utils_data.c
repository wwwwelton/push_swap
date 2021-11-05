/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 04:21:57 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	init_failed(t_data *data)
{
	if (!data->stack_a->items || !data->stack_b->items
		|| !data->operations || !data->options)
		return (TRUE);
	return (FALSE);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->stack_a = new_stack(argc - 1);
	data->stack_b = new_stack(argc - 1);
	data->options = ft_split(OPTIONS, ' ');
	data->operations = ft_strdup("");
	if (init_failed(data))
		exit_error("Memory allocation failed\n", 1, data);
	data->argc = argc;
	data->argv = argv;
}

void	deinit_data(t_data *data)
{
	ft_free_ptr((void *)&data->stack_a->items);
	ft_free_ptr((void *)&data->stack_b->items);
	ft_free_ptr((void *)&data->stack_a);
	ft_free_ptr((void *)&data->stack_b);
	ft_free_ptr((void *)&data->operations);
	free_splited_mat(data->options);
}
