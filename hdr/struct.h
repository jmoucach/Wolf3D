/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/10 15:58:08 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "Wolf3d.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct 		s_d_point
{
	double			x;
	double			y;
}					t_d_point;

typedef	struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef	struct		s_player
{
	double angle;
	t_d_point		pos; // position du joueur/ camera
	t_point		screen_pos;
	int fov;
	t_d_point		dir; // direction dans laquelle la camera regarde
	t_d_point		plane; // plan de projection
	double			walkSpeed;
	double			rotSpeed;
}					t_player;

typedef struct s_box
{
	int value;
	int edges[4];
}				t_box;

typedef struct s_edge
{
	t_point start;
	t_point end;
}				t_edge;



typedef	struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*pixels;
	t_edge			*edges;
	int				edge_nb;
	SDL_Event		event;
	t_player		player;
	t_box				**map;
	t_point			mapSize;
	int				box_length;
	short			quit;
}					t_data;

#endif
