/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 04:26:07 by wleite           ###   ########.fr       */
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
