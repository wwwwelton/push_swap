/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 01:05:39 by wleite           ###   ########.fr       */
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

static void	print_operations(char *operations)
{
	int		i;
	char	**splited_operations;

	splited_operations = ft_split(operations, ' ');
	i = -1;
	while (splited_operations[++i])
		ft_putstr_fd(splited_operations[i], 1);
	free_splited_mat(splited_operations);
}

static void	optimize_operations(char **operations)
{
	while (ft_strnstr(*operations, "\nra\nrb\n", ft_strlen(*operations)))
		*operations = ft_str_replace(*operations, "\nra\nrb\n", "\nrr\n");
	while (ft_strnstr(*operations, "\nrb\nra\n", ft_strlen(*operations)))
		*operations = ft_str_replace(*operations, "\nrb\nra\n", "\nrr\n");
	while (ft_strnstr(*operations, "\nrra\nrrb\n", ft_strlen(*operations)))
		*operations = ft_str_replace(*operations, "\nrra\nrrb\n", "\nrrr\n");
	while (ft_strnstr(*operations, "\nrrb\nrra\n", ft_strlen(*operations)))
		*operations = ft_str_replace(*operations, "\nrrb\nrra\n", "\nrrr\n");
}

void	print_best_algo(t_data *data)
{
	optimize_operations(&data->algo_a->operations);
	if (data->algo_a->op_count <= data->algo_b->op_count)
		print_operations(data->algo_a->operations);
	else
		print_operations(data->algo_b->operations);
}
