/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/21 08:41:58 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args_count)
	{
		if (valid_number(data->argv[i + 1]) == true)
			data->args[i] = ft_atoi(data->argv[i + 1]);
		else
			exit_error(NULL, 1, data);
	}
	if (unique_numbers(data->args, data->args_count) == false)
		exit_error(NULL, 1, data);
}
