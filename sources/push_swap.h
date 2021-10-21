/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/21 08:38:04 by wleite           ###   ########.fr       */
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
	int		args_count;
	int		*args;
	char	**argv;
	t_algo	*algo_a;
	t_algo	*algo_b;
}	t_data;

int		push_swap(int argc, char **argv);

void	*new_array(size_t number, size_t size);
t_stack	*new_stack(int capacity);
t_algo	*new_algo(int capacity);

void	init_data(int argc, char **argv, t_data *data);
void	deinit_data(t_data *data);

void	exit_error(char *message, int status_code, t_data *data);
void	get_args(t_data *data);

int		valid_number(char *nbr);
int		unique_numbers(int	*nbrs, int size);

#endif
