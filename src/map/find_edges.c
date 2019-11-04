/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:23:44 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 17:20:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short			find_edge_north(t_data *data, t_edge_list **edges, int x, int y)
{
	t_box		**map;
	t_edge_list	*first;

	map = data->map;
	if (y - 1 > 0 && map[y - 1][x].value == 0)
	{
		if (x - 1 > 0 && map[y][x - 1].value > 0
			&& map[y][x - 1].edges[NORTH] >= 0)
		{
			first = *edges;
			map[y][x].edges[NORTH] = map[y][x - 1].edges[NORTH];
			while (*edges && (*edges)->id != map[y][x - 1].edges[NORTH])
				*edges = (*edges)->next;
			(*edges)->edge.end.x = (x + 1) * 16;
			*edges = first;
		}
		else if (!new_edge_north(data, edges, x, y))
			return (0);
	}
	else
		map[y][x].edges[NORTH] = -1;
	return (1);
}

short			find_edge_south(t_data *data, t_edge_list **edges, int x, int y)
{
	t_box		**map;
	t_edge_list	*first;

	map = data->map;
	if (y + 1 < data->msize.y && map[y + 1][x].value == 0)
	{
		if (x - 1 > 0 && map[y][x - 1].value > 0
			&& map[y][x - 1].edges[SOUTH] >= 0)
		{
			first = *edges;
			map[y][x].edges[SOUTH] = map[y][x - 1].edges[SOUTH];
			while (*edges && (*edges)->id != map[y][x - 1].edges[SOUTH])
				*edges = (*edges)->next;
			(*edges)->edge.end.x = (x + 1) * 16;
			*edges = first;
		}
		else if (!new_edge_south(data, edges, x, y))
			return (0);
	}
	else
		map[y][x].edges[SOUTH] = -1;
	return (1);
}

short			find_edge_east(t_data *data, t_edge_list **edges, int x, int y)
{
	t_box		**map;
	t_edge_list	*first;

	map = data->map;
	if (x + 1 < data->msize.x && map[y][x + 1].value == 0)
	{
		if (y - 1 > 0 && map[y - 1][x].value > 0
			&& map[y - 1][x].edges[EAST] >= 0)
		{
			first = *edges;
			map[y][x].edges[EAST] = map[y - 1][x].edges[EAST];
			while (*edges && (*edges)->id != map[y - 1][x].edges[EAST])
				*edges = (*edges)->next;
			(*edges)->edge.end.y = (y + 1) * 16;
			*edges = first;
		}
		else if (!new_edge_east(data, edges, x, y))
			return (0);
	}
	else
		map[y][x].edges[EAST] = -1;
	return (1);
}

short			find_edge_west(t_data *data, t_edge_list **edges, int x, int y)
{
	t_box		**map;
	t_edge_list	*first;

	map = data->map;
	if (x - 1 > 0 && map[y][x - 1].value == 0)
	{
		if (y - 1 > 0 && map[y - 1][x].value > 0
			&& map[y - 1][x].edges[WEST] >= 0)
		{
			first = *edges;
			map[y][x].edges[WEST] = map[y - 1][x].edges[WEST];
			while (*edges && (*edges)->id != map[y - 1][x].edges[WEST])
				*edges = (*edges)->next;
			(*edges)->edge.end.y = (y + 1) * 16;
			*edges = first;
		}
		else if (!new_edge_west(data, edges, x, y))
			return (0);
	}
	else
		map[y][x].edges[WEST] = -1;
	return (1);
}

short			find_edges(t_data *data)
{
	int			x;
	int			y;
	t_edge_list	*edges;

	y = -1;
	edges = NULL;
	while (++y < data->msize.y)
	{
		x = -1;
		while (++x < data->msize.x)
		{
			if (data->map[y][x].value > 0)
			{
				if (!find_edge_north(data, &edges, x, y)
					|| !find_edge_south(data, &edges, x, y)
					|| !find_edge_east(data, &edges, x, y)
					|| !find_edge_west(data, &edges, x, y))
					return (0);
			}
		}
	}
	copy_edges_to_array(data, edges);
	delete_edge_list(&edges);
	print_edges_array(data);
	return (1);
}
