/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/10/16 06:03:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_error(char *message, int status_code, t_data *data)
{
	deinit_data(data);
	ft_putstr_fd("Error\n", 1);
	if (message)
	{
		ft_putstr_fd(message, 1);
		ft_putstr_fd("\n", 1);
	}
	exit(status_code);
}
