/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/24 13:51:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define BHRED "\e[1;91m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define PINK "\e[0;35m"
# define reset "\e[0m"

void	print_stack_a(t_algo *algo)
{
	int	i;

	printf("\nSize A: %d\n", algo->stack_a->size);
	i = -1;
	while (++i < algo->stack_a->size)
		printf(BHRED"[%d] "reset, i);
	printf("\n");
	i = -1;
	while (++i < algo->stack_a->size)
		printf(YEL"[%d] "reset, algo->stack_a->items[i]);
	printf("\n\n");
}

void	print_stack_b(t_algo *algo)
{
	int	i;

	printf("\nSize B: %d\n", algo->stack_b->size);
	i = -1;
	while (++i < algo->stack_b->size)
		printf(BHRED"[%d] "reset, i);
	printf("\n");
	i = -1;
	while (++i < algo->stack_b->size)
		printf(YEL"[%d] "reset, algo->stack_b->items[i]);
	printf("\n\n");
}

void	print_stack(t_stack *stack, char letter)
{
	int	i;

	printf("\nSize %c: %d\n", letter, stack->size);
	i = -1;
	while (++i < stack->size)
		printf(BHRED"[%d] "reset, i);
	printf("\n");
	i = -1;
	while (++i < stack->size)
		printf(YEL"[%d] "reset, stack->items[i]);
	printf("\n\n");
}

void	print_stack_ab(t_algo *algo)
{
	int	i;

	i = -1;
	printf("\nSize A: %d\nSize B: %d\nOperat: %d\n", algo->stack_a->size, algo->stack_b->size, algo->op_count);
	printf("========\n");
	printf(GRN"%2c"reset, 'I');
	printf(YEL"%6c"reset, 'A');
	printf(RED"%6c\n"reset, 'B');
	while (++i < algo->stack_a->maxsize)
	{
		if (i >= (int)algo->stack_a && i >= (int)algo->stack_b)
			break ;
		printf(GRN"[%d] | "reset, i);
		if (i < (int)algo->stack_a->size)
			printf(YEL"[%d] | "reset, algo->stack_a->items[i]);
		else
			printf(YEL"[ ] | "reset);
		if (i < (int)algo->stack_b->size)
			printf(RED"[%d]"reset, algo->stack_b->items[i]);
		else
			printf(RED"[ ]"reset);
		printf("\n");
	}
	printf("========\n");
	printf("\n");
}
