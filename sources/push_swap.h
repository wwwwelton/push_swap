/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/20 12:52:03 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdbool.h"
# include "../libraries/libft/libft.h"

typedef struct s_stack
{
	int	maxsize;
	int	top;
	int	*items;
}	t_stack;

typedef struct s_algo
{
	int		op_count;
	char	*operations;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_algo;

typedef struct s_data
{
	int		argc;
	int		*args;
	char	**argv;
	t_algo	algo_a;
	t_algo	algo_b;
}	t_data;

int	push_swap(int argc, char **argv);

#endif
