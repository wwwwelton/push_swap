/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 13:42:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *nbr)
{
	int			i;
	int			big_digits;
	long int	n;

	big_digits = 0;
	i = -1;
	while (nbr[++i] != '\0')
	{
		if (nbr[i] == '-' && nbr[i + 1] == '\0')
			return (false);
		else if (!ft_isdigit(nbr[i]) && nbr[i] != '-')
			return (false);
		else if (ft_isdigit(nbr[i]) && nbr[i + 1] == '-')
			return (false);
		if (nbr[i] >= '1' && nbr[i] <= '9')
			big_digits++;
	}
	n = ft_atol(nbr);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	if (n == 0 && big_digits)
		return (false);
	return (true);
}

int	unique_numbers(int	*nbrs, int size)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	while (++i < size)
	{
		found = 0;
		j = -1;
		while (++j < size)
		{
			if (nbrs[i] == nbrs[j])
				found++;
			if (found > 1)
				return (false);
		}
	}
	return (true);
}

int	is_sorted(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < (size - 1))
		if (array[i] > array[i + 1])
			return (false);
	return (true);
}

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
