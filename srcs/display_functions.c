/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <tcherret@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:37:46 by tcherret          #+#    #+#             */
/*   Updated: 2019/04/12 22:15:08 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(int *path, int nb, t_farm *farm)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_printf(CYAN_TEXT "%s " COLOR_RESET, farm->room[path[i]].name);
	ft_printf("\n");
}
