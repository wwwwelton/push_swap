/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 21:46:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_to_code(char *op)
{
	int	i;

	i = 0;
	i += *op;
	while (*op)
		i += *op++;
	return (i);
}

char	*code_to_op(int op, char **options)
{
	int	i;

	i = -1;
	while (options[++i])
	{
		if ((op_to_code(options[i]) - '\n') == op)
			return (ft_strdup(options[i]));
	}
	return (NULL);
}
