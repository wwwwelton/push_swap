/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 14:02:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	debug_stack_a(t_data *data)
{
	int	i;

	i = -1;
	printf("\nStack A\n");
	printf("Size: %d\n", data->size_a);
	printf("========\n");
	while (++i < data->size_a)
		printf("index: %d | stack: %d\n", i, data->stack_a[i]);
	printf("========\n");
	printf("\n");
}

void	debug_stack_b(t_data *data)
{
	int	i;

	i = -1;
	printf("\nStack B\n");
	printf("Size: %d\n", data->size_b);
	printf("========\n");
	while (++i < data->size_b)
		printf("index: %d | stack: %d\n", i, data->stack_b[i]);
	printf("========\n");
	printf("\n");
}

void	debug_stack_a_b(t_data *data)
{
	int	i;

	i = -1;
	printf("\nSize A: %d | Size B: %d\n", data->size_a, data->size_b);
	printf("========\n");
	while (++i < data->stack_size)
	{
		if (i >= (int)data->stack_a && i >= (int)data->stack_b)
			break ;
		printf("index: %d | ", i);
		if (i < (int)data->size_a)
			printf("Stack A: %d | ", data->stack_a[i]);
		else
			printf("Stack A:   | ");
		if (i < (int)data->size_b)
			printf("Stack B: %d", data->stack_b[i]);
		else
			printf("Stack B:  ");
		printf("\n");
	}
	printf("========\n");
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
