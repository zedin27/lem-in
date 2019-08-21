/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:05:44 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/15 23:26:58 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				check_name(char *name, t_farm *farm, int nb)
{
	int		i;

	i = 0;
	while (i < nb && farm->room[i].name)
	{
		if (ft_strcmp(farm->room[i].name, name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				check_coor(int x, int y, t_farm *farm, int nb)
{
	int i;

	i = 0;
	while (i < nb && farm->room[i].x && farm->room[i].y)
	{
		if (x == farm->room[i].x && y == farm->room[i].y)
			return (1);
		i++;
	}
	return (0);
}

int				check_valid_start_end(t_farm farm)
{
	if (farm.init_start == 2 && farm.init_end == 2)
		return (1);
	return (-1);
}

int				invalid_farm(char **line, t_farm *farm)
{
	free_farm(farm);
	ft_printf(RED_TEXT "ERROR.\n" COLOR_RESET);
	if (line != NULL)
		ft_printf(RED_TEXT "The farm is not valid because of line: %s !\n"
				COLOR_RESET, *line);
	ft_strdel(line);
	return (-1);
}

int				valid_farm(t_farm *farm)
{
	free_farm(farm);
	return (0);
}
