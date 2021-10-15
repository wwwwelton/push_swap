/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:31 by wleite            #+#    #+#             */
/*   Updated: 2021/10/15 18:29:33 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "stdbool.h"
# include "../libraries/libft/libft.h"

typedef struct s_data
{
	char	**stack_a;
	char	**stack_b;
	char	**ops;
	int		ops_count;
	bool	stack_ordered;
}	t_data;

int		checker(int argc, char **argv);

void	init_checker(t_data *data);

#endif
