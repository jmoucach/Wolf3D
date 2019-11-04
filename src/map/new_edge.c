/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:55:50 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 17:12:03 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short			new_edge_north(t_data *data, t_edge_list **edges, int x, int y)
{
	t_edge_list	*tmp;

	data->edge_nb++;
	if (*edges == NULL)
		*edges = create_edge_list((t_point){16 * x, 16 * y},
			(t_point){16 * (x + 1), 16 * y}, data->edge_nb);
	else
	{
		if (!(tmp = (t_edge_list *)malloc(sizeof(t_edge_list))))
			return (0);
		tmp->edge.start.x = 16 * x;
		tmp->edge.start.y = 16 * y;
		tmp->edge.end.x = 16 * (x + 1);
		tmp->edge.end.y = 16 * y;
		tmp->id = data->edge_nb;
		pushback_edge(edges, tmp);
	}
	data->map[y][x].edges[NORTH] = data->edge_nb;
	return (1);
}

short			new_edge_south(t_data *data, t_edge_list **edges, int x, int y)
{
	t_edge_list	*tmp;

	data->edge_nb++;
	if (*edges == NULL)
		*edges = create_edge_list((t_point){16 * x, 16 * (1 + y)},
			(t_point){16 * (x + 1), 16 * (1 + y)}, data->edge_nb);
	else
	{
		if (!(tmp = (t_edge_list *)malloc(sizeof(t_edge_list))))
			return (0);
		tmp->edge.start.x = 16 * x;
		tmp->edge.start.y = 16 * (y + 1);
		tmp->edge.end.x = 16 * (x + 1);
		tmp->edge.end.y = 16 * (y + 1);
		tmp->id = data->edge_nb;
		pushback_edge(edges, tmp);
	}
	data->map[y][x].edges[SOUTH] = data->edge_nb;
	return (1);
}

short			new_edge_east(t_data *data, t_edge_list **edges, int x, int y)
{
	t_edge_list	*tmp;

	data->edge_nb++;
	if (*edges == NULL)
		*edges = create_edge_list((t_point){16 * (1 + x), 16 * y},
			(t_point){16 * (x + 1), 16 * (1 + y)}, data->edge_nb);
	else
	{
		if (!(tmp = (t_edge_list *)malloc(sizeof(t_edge_list))))
			return (0);
		tmp->edge.start.x = 16 * (x + 1);
		tmp->edge.start.y = 16 * y;
		tmp->edge.end.x = 16 * (x + 1);
		tmp->edge.end.y = 16 * (y + 1);
		tmp->id = data->edge_nb;
		pushback_edge(edges, tmp);
	}
	data->map[y][x].edges[EAST] = data->edge_nb;
	return (1);
}

short			new_edge_west(t_data *data, t_edge_list **edges, int x, int y)
{
	t_edge_list	*tmp;

	data->edge_nb++;
	if (*edges == NULL)
		*edges = create_edge_list((t_point){16 * x, 16 * y},
			(t_point){16 * x, 16 * (1 + y)}, data->edge_nb);
	else
	{
		if (!(tmp = (t_edge_list *)malloc(sizeof(t_edge_list))))
			return (0);
		tmp->edge.start.x = 16 * x;
		tmp->edge.start.y = 16 * y;
		tmp->edge.end.x = 16 * x;
		tmp->edge.end.y = 16 * (y + 1);
		tmp->id = data->edge_nb;
		pushback_edge(edges, tmp);
	}
	data->map[y][x].edges[WEST] = data->edge_nb;
	return (1);
}
