/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <tcherret@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:31:09 by tcherret          #+#    #+#             */
/*   Updated: 2019/04/03 16:08:12 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# define SIZE 256
# define COLOR_RESET	"\033[0m"
# define BOLD			"\033[1m"
# define BLACK_TEXT		"\033[30;1m"
# define RED_TEXT		"\033[31;1m"
# define GREEN_TEXT		"\033[32;1m"
# define YELLOW_TEXT	"\033[33;1m"
# define BLUE_TEXT		"\033[34;1m"
# define MAGENTA_TEXT	"\033[35;1m"
# define CYAN_TEXT		"\033[36;1m"
# define WHITE_TEXT		"\033[37;1m"

/*
** Data structures to stock the information
*/

typedef struct		s_room
{
	char	*name;
	int		index;
	int		ant;
	int		x;
	int		y;
	int		start;
	int		end;
	int		visited;
	int		weight;
	int		ant_name;
}					t_room;

typedef struct		s_path
{
	int		*path;
	int		weight;
	int		c_weight;
	int		ants_to_send;
}					t_path;

typedef struct		s_farm
{
	t_room	*room;
	t_path	*path;
	int		**link;
	int		total;
	int		nb_room;
	int		nb_path;
	int		init_start;
	int		init_end;
	int		init_total;
	int		create_matrix;
	int		size;
	int		optionp;
	int		optionc;
	int		first;
	int		last;
	int		count;
	int		path_max;
	int		ant_name;
	int		counter;
	int		flow;
	int		nb_queue;
}					t_farm;

/*
** Functions to get the informations from the stdinput
*/

int					is_nb_info(char *str);
int					is_room_info(char *str, t_farm *farm, int i);
int					check_coor(int x, int y, t_farm *farm, int nb);
int					ft_realloc_room(t_farm *farm, int old_nb_room);
int					is_link_info(char *str, t_farm *farm);
int					create_link_matrix(t_farm *farm, char *line);
void				fill_the_matrix(t_farm *farm);
int					is_comment(char *str, t_farm *farm);
void				free_tab(char **tab);
int					check_name(char *name, t_farm *farm, int nb);
void				get_option(int ac, char **av, t_farm *farm);
int					check_valid_start_end(t_farm farm);
void				free_farm(t_farm *farm);
void				free_tab(char **tab);
int					invalid_farm(char **line, t_farm *farm);
int					valid_farm(t_farm *farm);
int					find_start(t_farm *farm);
int					find_end(t_farm *farm);
int					undefined_map(void);

/*
** Algorithms to find the shortests paths and manage the flow
*/

int					bfs(t_farm *farm);
void				enqueue(int vertex, int **queue, t_farm *farm);
int					dequeue(int **queue, t_farm *farm);
int					is_empty(t_farm *farm);
void				put_vertex_visited(int ind, t_farm *farm);
int					check_enqueue(int *queue, int i, t_farm *farm);
void				create_path(int **path, int *queue, t_farm *farm, int nb);
int					path_found(t_farm *farm, int **queue, int end, int vertex);
int					check_duplicate_path(t_farm *farm, int vertex);

/*
** Functions to move the ants, to check the room and to display
*/

int					moving_display(t_farm *farm);
int					move_ant(t_room *src, t_room *dst, t_farm *farm);
int					check_room_free(t_room *room);
int					graph_finished(t_farm *farm);
void				print_path(int *path, int nb, t_farm *farm);

#endif
