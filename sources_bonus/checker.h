/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 04:33:19 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stdbool.h"
# include "stdio.h"
# include "../libraries/libft/libft.h"

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		argc;
	int		ops_count;
	int		stack_size;
	char	*ops;
	char	**argv;
	bool	stack_ordered;
}	t_data;

int		checker(int argc, char **argv);

void	init_data(int argc, char **argv, t_data *data);
void	deinit_data(t_data *data);

void	get_args(t_data *data);

void	*new_array(size_t number, size_t size);

void	debug_stack_a(int *stack, int size);

void	exit_error(t_data *data);

int		valid_number(char *nbr);

#endif
