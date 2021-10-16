/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 04:34:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->stack_size)
	{
		if (valid_number(data->argv[i + 1]) == true)
			data->stack_a[i] = ft_atoi(data->argv[i + 1]);
		else
			exit_error(data);
	}
}
