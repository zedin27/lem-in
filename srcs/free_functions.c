/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:39:14 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 16:06:02 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_farm_link(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->nb_room)
	{
		free(farm->link[i]);
		i++;
	}
	free(farm->link);
}

void		free_farm(t_farm *farm)
{
	int i;

	i = 0;
	if (farm->room != NULL)
	{
		while (i < farm->nb_room)
		{
			free(farm->room[i].name);
			i++;
		}
		free(farm->room);
	}
	if (farm->link != NULL)
		free_farm_link(farm);
	i = 0;
	if (farm->path != NULL)
	{
		while (i < farm->nb_path)
		{
			free(farm->path[i].path);
			i++;
		}
		free(farm->path);
	}
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while ((tab)[i] != NULL)
	{
		free((tab)[i]);
		i++;
	}
	free(tab);
}
