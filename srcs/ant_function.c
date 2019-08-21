/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:15:38 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/14 23:03:22 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	save_space0(t_room *src, t_room *dst, t_farm *farm)
{
	src->ant--;
	dst->ant++;
	dst->ant_name = farm->ant_name++;
}

int			move_ant(t_room *src, t_room *dst, t_farm *farm)
{
	if (src->start == 1 && dst->end == 1)
		save_space0(src, dst, farm);
	else if (src->start == 1)
	{
		src->ant--;
		dst->ant = 1;
		dst->ant_name = farm->ant_name++;
	}
	else if (src->ant == 1 && dst->end == 1)
	{
		src->ant = 0;
		dst->ant++;
		dst->ant_name = src->ant_name;
	}
	else if (src->ant == 1 && dst->ant == 0)
	{
		src->ant = 0;
		dst->ant = 1;
		dst->ant_name = src->ant_name;
	}
	else
		return (0);
	return (1);
}

int			check_room_free(t_room *room)
{
	int k;

	if (room->end == 1)
		return (0);
	k = (room->ant == 0) ? 0 : 1;
	return (k);
}

int			graph_finished(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->nb_room)
	{
		if (farm->room[i].end == 1)
		{
			if (farm->room[i].ant != farm->total)
				return (-1);
		}
		else if (farm->room[i].ant != 0)
			return (-1);
		i++;
	}
	return (1);
}
