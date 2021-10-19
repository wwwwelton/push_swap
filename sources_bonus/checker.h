/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/19 00:44:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stdbool.h"
# include "stdio.h"
# include "../libraries/libft/libft.h"

# ifndef OPTIONS
#  define OPTIONS "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n"
# endif

# define SA 133
# define SB 134
# define SS 151
# define PA 127
# define PB 128
# define RA 131
# define RB 132
# define RR 148
# define RRA 148
# define RRB 149
# define RRR 165

typedef struct s_stack
{
	int	maxsize;
	int	top;
	int	*items;
}	t_stack;

typedef struct s_data
{
	int		argc;
	char	*operations;
	char	**options;
	char	**argv;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

int		checker(int argc, char **argv);

void	init_data(int argc, char **argv, t_data *data);
void	deinit_data(t_data *data);

void	get_args(t_data *data);
void	get_ops(t_data *data);

void	*new_array(size_t number, size_t size);
void	free_splited_mat(char **mat);

void	debug_stack_a(t_data *data);
void	debug_stack_b(t_data *data);
void	debug_stack_a_b(t_data *data);
void	debug_ops(t_data *data);
void	debug_print_stack_a_order(t_data *data);
void	debug_print_stack_b_order(t_data *data);

void	exit_error(char *message, int status_code, t_data *data);

int		valid_number(char *nbr);
int		valid_opt(char *opt, char **opts);
int		unique_numbers(int	*nbrs, int size);

void	set_ops(t_data *data);

void	swap(int op, t_data *data);
void	push(int op, t_data *data);
void	rotate(int op, t_data *data);
void	rrotate(int op, t_data *data);

int		stack_is_sorted(t_stack *stack);
int		valid_sort(t_data *data);

t_stack	*new_stack(int capacity);

#endif
