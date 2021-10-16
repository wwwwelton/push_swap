/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 07:06:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	debug_stack_a(t_data *data)
{
	int	i;

	i = -1;
	printf("\nStack A:\n");
	while (++i < data->stack_size)
		printf("index: %d | stack: %d\n", i, data->stack_a[i]);
	printf("\n");
}

void	debug_ops(t_data *data)
{
	int		i;
	char	**tmp;

	tmp = ft_split(data->operations, ' ');
	if (!tmp)
	{
		printf("\nNULL operations\n\n");
		return ;
	}
	else if (!*tmp)
	{
		printf("\nEmpty operations\n\n");
		free_splited_mat(tmp);
		return ;
	}
	printf("\nOperations:\n");
	i = -1;
	while (tmp[++i])
		printf("op: %d | =>%s<=\n", i, tmp[i]);
	free_splited_mat(tmp);
	printf("\n");
}
