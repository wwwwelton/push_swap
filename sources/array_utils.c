/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/05 04:21:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < (size - 1))
		if (array[i] > array[i + 1])
			return (FALSE);
	return (TRUE);
}

void	brute_sort(int *array, int size)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = TRUE;
	while (swapped)
	{
		swapped = FALSE;
		i = -1;
		while (++i < (size - 1))
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = TRUE;
			}
		}
	}
}

int	get_index(int *array, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
		if (array[i] == n)
			return (i);
	return (INT_MAX);
}

int	get_smallest_nbr(int *array, int size)
{
	int	i;
	int	n;

	i = -1;
	n = array[0];
	while (++i < size)
		if (array[i] < n)
			n = array[i];
	return (n);
}

int	get_biggest_nbr(int *array, int size)
{
	int	i;
	int	n;

	i = -1;
	n = array[0];
	while (++i < size)
		if (array[i] > n)
			n = array[i];
	return (n);
}
