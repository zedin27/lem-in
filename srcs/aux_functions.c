/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:51:22 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/02 13:32:47 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_start(t_farm *farm)
{
	int i;
	int start;

	i = 0;
	while (farm->room[i].start != 1)
		i++;
	start = i;
	return (start);
}

int		find_end(t_farm *farm)
{
	int i;
	int end;

	i = 0;
	while (farm->room[i].end != 1)
		i++;
	end = i;
	return (end);
}

int		undefined_map(void)
{
	ft_printf("ERROR.\n");
	return (-1);
}
