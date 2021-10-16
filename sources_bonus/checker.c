/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 14:50:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	get_args(&data);
	get_ops(&data);
	set_ops(&data);
	deinit_data(&data);
	return (EXIT_SUCCESS);
}
