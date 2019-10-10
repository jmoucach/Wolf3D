/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/07 11:52:59 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

#include "Wolf3d.h"

/*
** INIT
*/

short create_renderer_texture_and_pixels(t_data *data);
short	init(t_data *data);
void	set_values(t_data *data);

/*
** Draw
*/

void	draw_rect_to_sdl(t_point pt_one, t_point pt_two, t_data *data, int colour);
void setup_param(t_point pt_one, t_point pt_two, t_line_param *line_param);
void	drawline(t_point pt_one, t_point pt_two, t_data *data, int colour);

/*
** Main
*/

void	close_all(t_data *data);


/*
** New map
*/

char *join_strings(char *s1, char *s2);
short	count_lines_and_col(t_data *data, char *str);
short	allocate_map(t_data *data);
char *read_map(int fd);
short	new_map(t_data *data, char *title);

/*
** Fill map
*/

void	print_map(t_data data);
short	fill_map(t_data *data, char *str);
short	parse_map(char *str);

/*
** Draw map box
*/

void draw_map_box(t_data *data);

/*
** Raycast
*/

void	cast_ray(t_data *data);

/*
** Event loop
*/

void	game_loop(t_data *data);

/*
** Show player
*/

void	show_player(t_data *data);

/*
** New edge
*/

void	copy_edge_data(t_edge **tmp, t_edge*edge, int i);
short new_edge_north(t_data *data, int x, int y);
short new_edge_south(t_data *data, int x, int y);
short new_edge_east(t_data *data, int x, int y);
short new_edge_west(t_data *data, int x, int y);

/*
** Find edges
*/

short find_edge_north(t_data *data, int x, int y);
short find_edge_south(t_data *data, int x, int y);
short find_edge_east(t_data *data, int x, int y);
short find_edge_west(t_data *data, int x, int y);
short find_edges(t_data *data);

/*
** Realloc edge
*/

void 	realloc_edge(t_data *data);
// t_edge *realloc_edge(t_edge **edge, int edge_nb);


#endif
