/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/24 13:06:03 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < (size - 1))
		if (array[i] > array[i + 1])
			return (false);
	return (true);
}

int	is_reverse_sorted(int *array, int size)
{
	int	i;

	i = size;
	while (--i > 0)
		if (array[i] > array[i - 1])
			return (false);
	return (true);
}
