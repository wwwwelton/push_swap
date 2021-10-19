/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/19 01:22:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	debug_stack_a_b(t_data *data)
{
	int	i;

	i = -1;
	printf("\nSize A: %d | Size B: %d\n", data->stack_a->top, data->stack_b->top);
	printf("========\n");
	while (++i < data->stack_a->maxsize)
	{
		if (i >= (int)data->stack_a && i >= (int)data->stack_b)
			break ;
		printf("index: %d | ", i);
		if (i < (int)data->stack_a->top)
			printf("Stack A: %d | ", data->stack_a->items[i]);
		else
			printf("Stack A:   | ");
		if (i < (int)data->stack_b->top)
			printf("Stack B: %d", data->stack_b->items[i]);
		else
			printf("Stack B:  ");
		printf("\n");
	}
	printf("========\n");
	printf("\n");
}

void	debug_print_stack_a_order(t_data *data)
{
	int	i;

	i = -1;
	printf("\nStack A: \n");
	printf("========\n");
	printf("value => ");
	while (++i < data->stack_a->top)
		printf("[%d] ", data->stack_a->items[i]);
	printf("\n");
	printf("index => ");
	i = -1;
	while (++i < data->stack_a->top)
		printf("[%d] ", i);
	printf("\n========\n");
	printf("\n");
}

void	debug_print_stack_b_order(t_data *data)
{
	int	i;

	i = -1;
	printf("\nStack B: \n");
	printf("========\n");
	printf("value => ");
	while (++i < data->stack_b->top)
		printf("[%d] ", data->stack_b->items[i]);
	printf("\n");
	printf("index => ");
	i = -1;
	while (++i < data->stack_b->top)
		printf("[%d] ", i);
	printf("\n========\n");
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
