/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:16:19 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/02 11:14:54 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_option(int ac, char **av, t_farm *farm)
{
	if (ac > 3 || ac == 1)
		return ;
	if (av[1])
	{
		if (ft_strcmp(av[1], "-p") == 0)
			farm->optionp = 1;
		if (ft_strcmp(av[1], "-c") == 0)
			farm->optionc = 1;
	}
	if (av[2])
	{
		if (ft_strcmp(av[2], "-c") == 0)
			farm->optionc = 1;
		if (ft_strcmp(av[2], "-p") == 0)
			farm->optionp = 1;
	}
}
