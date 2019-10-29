/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/29 17:13:19 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H
#include "Wolf3d.h"

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_d_point
{
	double x;
	double y;
} t_d_point;

typedef struct s_line_param
{
	t_point diff;
	t_point inc;
	int error;
	int off;
} t_line_param;

typedef struct s_ray
{
	t_d_point pos;
	t_d_point dir;
}				t_ray;

typedef struct s_player
{
	double angle;
	t_d_point plane; // position du joueur/ camera
	t_d_point pos; // position du joueur/ camera
	t_point screen_pos;
	int fov;
	t_d_point dir;   // direction dans laquelle la camera regarde
	double walkSpeed;
	double rotationSpeed;
} t_player;

typedef struct s_raycast
{
	t_ray 		ray;
	double camera;
	t_point m_pos;
	t_d_point sidedist;
	t_d_point deltadist;
	t_point step;
	int hit;
	double wallX;
	int side;
	int texH;
	int texW;
	int texNum;
	t_point tex;
	int lineHeight;
	Uint32 color;
	int drawstart;
	int drawend;
	double wallDist;
}				t_raycast;

typedef struct s_box
{
	int value;
	int edges[4];
} t_box;

typedef struct s_edge
{
	t_point start;
	t_point end;
} t_edge;

typedef struct s_edge_list
{
	int id;
	t_edge edge;
	struct s_edge_list *next;
}	t_edge_list;

typedef struct s_data
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Surface **surface;
	Uint32 *pixels;
	t_edge *edges;
	int edge_nb;
	SDL_Event event;
	t_player player;
	t_box **map;
	t_point mapSize;
	int box_length;
	short quit;
} t_data;

#endif
