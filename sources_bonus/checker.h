/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/18 15:32:48 by wleite           ###   ########.fr       */
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

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		argc;
	int		op_count;
	int		stack_size;
	int		size_a;
	int		size_b;
	char	*operations;
	char	**options;
	char	**argv;
	bool	stack_ordered;
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

void	exit_error(char *message, int status_code, t_data *data);

int		valid_number(char *nbr);
int		valid_opt(char *opt, char **opts);
int		unique_numbers(int	*nbrs, int size);

void	set_ops(t_data *data);

void	swap(int **stack_a, int *size_a, int **stack_b, int *size_b);
void	push(int **stack_from, int *size_from, int **stack_to, int *size_to);
void	rotate(int **stack_a, int *size_a, int **stack_b, int *size_b);
void	rrotate(int **stack_a, int *size_a, int **stack_b, int *size_b);

#endif
