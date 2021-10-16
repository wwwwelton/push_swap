/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 07:00:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_number(char *nbr)
{
	int	i;
	int	big_digits;

	big_digits = 0;
	i = -1;
	while (nbr[++i] != '\0')
	{
		if (ft_isalpha(nbr[i]))
			return (false);
		else if (ft_isdigit(nbr[i]) && nbr[i + 1] == '-')
			return (false);
		if (nbr[i] >= '1' && nbr[i] <= '9')
			big_digits++;
	}
	if (ft_atoi(nbr) == 0 && big_digits)
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
