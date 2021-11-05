/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 04:21:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args_size)
	{
		if (valid_number(data->argv[i + 1]) == TRUE)
			data->args[i] = ft_atoi(data->argv[i + 1]);
		else
			exit_error(NULL, 1, data);
	}
	if (unique_numbers(data->args, data->args_size) == FALSE)
		exit_error(NULL, 1, data);
}
