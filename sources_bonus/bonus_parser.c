/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 07:13:06 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	get_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->stack_a->maxsize)
	{
		if (valid_number(data->argv[i + 1]) == true)
		{
			data->stack_a->items[i] = ft_atoi(data->argv[i + 1]);
			data->stack_a->top++;
		}
		else
			exit_error(NULL, 1, data);
	}
	if (unique_numbers(data->stack_a->items, data->stack_a->maxsize) == false)
		exit_error(NULL, 1, data);
}

void	get_ops(t_data *data)
{
	char	*tmp;

	while (1)
	{
		tmp = ft_get_next_line(STDIN_FILENO);
		if (tmp == NULL)
			return ;
		else if (tmp[0] == '\n' || valid_opt(tmp, data->options) == false)
		{
			ft_free_ptr((void *)&tmp);
			close(STDIN_FILENO);
			tmp = ft_get_next_line(STDIN_FILENO);
			exit_error(NULL, 1, data);
		}
		data->operations = ft_strmerge(data->operations, ft_strdup(" "));
		tmp = ft_str_replace(tmp, "\n", "\0");
		data->operations = ft_strmerge(data->operations, tmp);
	}
}
