/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 07:13:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

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

int	valid_opt(char *opt, char **opts)
{
	int		i;

	if (!opt)
		return (false);
	i = -1;
	while (opts[++i])
		if (ft_strncmp(opt, opts[i], ft_strlen(opts[i])) == 0)
			return (true);
	return (false);
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < (stack->top - 1))
		if (stack->items[i] > stack->items[i + 1])
			return (false);
	return (true);
}

int	valid_sort(t_data *data)
{
	if (stack_is_sorted(data->stack_a) && !data->stack_b->top)
		return (true);
	return (false);
}
