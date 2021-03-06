/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 14:33:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

# ifndef OPTIONS
#  define OPTIONS "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n"
# endif

# define SA 327
# define SB 328
# define SS 345
# define PA 321
# define PB 322
# define RA 325
# define RB 326
# define RR 342
# define RRA 439
# define RRB 440
# define RRR 456

typedef struct s_stack
{
	int	maxsize;
	int	size;
	int	top;
	int	*items;
}	t_stack;

typedef struct s_algo
{
	int		op_count;
	char	*operations;
	char	**options;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_algo;

typedef struct s_data
{
	int		argc;
	int		args_size;
	int		*args;
	char	**argv;
	t_algo	*algo_a;
	t_algo	*algo_b;
}	t_data;

int		get_biggest_nbr(int *array, int size);
int		get_index(int *array, int size, int n);
int		get_moves(t_stack *stack, int n);
int		get_smallest_nbr(int *array, int size);
int		is_sorted(int *array, int size);
int		op_to_code(char *op);
int		push_swap(int argc, char **argv);
int		put_nbr_to_index(int *array, int size, int n);
int		stack_is_empty(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		unique_numbers(int	*nbrs, int size);
int		valid_number(char *nbr);
int		valid_sort(t_algo *algo);
void	bubble_sort(int *array, int size);
void	deinit_data(t_data *data);
void	do_op(int op, t_algo *algo);
void	exit_error(char *message, int status_code, t_data *data);
void	free_splited_mat(char **mat);
void	get_args(t_data *data);
void	go_to(t_stack *stack, t_algo *algo, int n, char id);
void	go_to_best_comb(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	init_data(int argc, char **argv, t_data *data);
void	init_stack(t_stack *stack, int *items, int size);
void	normalize(int *array, int size);
void	print_best_algo(t_data *data);
void	push(int op, t_algo *algo);
void	rotate(int op, t_algo *algo);
void	rrotate(int op, t_algo *algo);
void	sort_algo_a(t_data *data);
void	sort_algo_b(t_data *data);
void	swap(int op, t_algo *algo);
void	*new_array(size_t number, size_t size);
char	*code_to_op(int op, char **options);
t_algo	*new_algo(int capacity);
t_stack	*new_stack(int capacity);

#endif
