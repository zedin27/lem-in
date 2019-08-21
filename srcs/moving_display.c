/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <tcherret@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/04/12 22:15:42 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			do_the_math(t_farm *farm)
{
	int	index;
	int	total;
	int	k;

	index = 0;
	total = farm->total;
	while (total > 0)
	{
		k = 0;
		while (k <= index && total > 0)
		{
			farm->path[k].ants_to_send++;
			total--;
			k++;
			if (index < farm->nb_path - 1 && (farm->path[index].ants_to_send
						+ farm->path[index].c_weight
						> farm->path[index + 1].c_weight))
				index++;
		}
	}
}

static int			create_j_no_overflow(t_farm *farm, int *j, int k)
{
	if (k < farm->path_max)
	{
		*j = farm->path[k].weight - 1;
		return (1);
	}
	else
		return (-1);
}

static void			move_print(t_farm *farm, int k, int j)
{
	if (create_j_no_overflow(farm, &j, k) != 1)
		return ;
	while (j > 1)
	{
		if (farm->room[farm->path[k].path[j - 1]].ant == 1)
		{
			move_ant(&farm->room[farm->path[k].path[j - 1]],
					&farm->room[farm->path[k].path[j]], farm);
			ft_printf("L%d-%s ", farm->room[farm->path[k].path[j]].ant_name,
					farm->room[farm->path[k].path[j]].name);
		}
		j--;
	}
	if (farm->path[k].ants_to_send > 0)
	{
		if (farm->room[farm->path[k].path[1]].ant == 0)
		{
			move_ant(&farm->room[farm->path[k].path[0]],
					&farm->room[farm->path[k].path[1]], farm);
			farm->path[k].ants_to_send--;
			ft_printf("L%d-%s ", farm->room[farm->path[k].path[1]].ant_name,
					farm->room[farm->path[k].path[1]].name);
		}
	}
}

static void			do_the_algo(t_farm *farm, int used)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (k <= used)
	{
		move_print(farm, k, j);
		k++;
	}
	farm->counter++;
	ft_printf("\n");
}

int					moving_display(t_farm *farm)
{
	int	start;
	int	used;

	used = 0;
	if (farm->optionp == 1)
		ft_printf("The number of path is : %d\n\n", farm->nb_path);
	start = find_start(farm);
	do_the_math(farm);
	while (used < farm->path_max && farm->path[used].ants_to_send > 0)
		used++;
	while (graph_finished(farm) != 1)
		do_the_algo(farm, used);
	if (farm->optionc == 1)
	ft_printf(GREEN_TEXT "\nNumber of turns : %d\n" COLOR_RESET,
			farm->counter);
	return (1);
}
