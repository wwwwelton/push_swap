/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:10:32 by wleite            #+#    #+#             */
/*   Updated: 2021/10/22 07:13:06 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		return (checker(argc, argv));
	return (EXIT_SUCCESS);
}
