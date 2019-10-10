/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:23:44 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/07 11:25:16 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short find_edge_north(t_data *data, int x, int y)
{
	t_box **map;

	map = data->map;
	if (y - 1 > 0 && map[y - 1][x].value == 0)
	{
		if (x - 1 > 0 && map[y][x - 1].value == 1)
		{
			if (map[y][x - 1].edges[NORTH] >= 0)
			{
				printf("lol\n");
				map[y][x].edges[NORTH] = map[y][x - 1].edges[NORTH];
				printf("ca casse\n");
				data->edges[map[y][x - 1].edges[NORTH]].end.x = (x + 1) * 16;
				printf("==========EDGE GIVEN==============\n");
			}
			else if (!new_edge_north(data, x, y))
				return (0);
		}
		else if (!new_edge_north(data, x, y))
			return (0);
	}
	else
		map[y][x].edges[NORTH] = -1;
	return (1);
}

short find_edge_south(t_data *data, int x, int y)
{
	t_box **map;

	map = data->map;
	if (y + 1 < data->mapSize.y && map[y + 1][x].value == 0)
	{

		if (x - 1 > 0 && map[y][x - 1].value == 1)
		{
			if (map[y][x - 1].edges[SOUTH] >= 0)
			{
				printf("lol\n");
				map[y][x].edges[SOUTH] = map[y][x - 1].edges[SOUTH];
				printf("ca casse\n");
				data->edges[map[y][x].edges[SOUTH]].end.x = (x + 1) * 16;
				printf("==========EDGE GIVEN==============\n");
			}
			else if (!new_edge_south(data, x, y))
				return (0);
		}
		else if (!new_edge_south(data, x, y))
			return (0);
	}
	else
		map[y][x].edges[SOUTH] = -1;
	return (1);
}

short find_edge_east(t_data *data, int x, int y)
{
	t_box **map;

	map = data->map;
	if (x + 1 < data->mapSize.x && map[y][x + 1].value == 0)
	{
		if (y - 1 > 0 && map[y - 1][x].value == 1)
		{
			if (map[y - 1][x].edges[EAST] >= 0)
			{
				printf("lol\n");
				map[y][x].edges[EAST] = map[y - 1][x].edges[EAST];
				printf("ca casse\n");
				data->edges[map[y][x].edges[EAST]].end.y = (y + 1) * 16;
				printf("==========EDGE GIVEN==============\n");
			}
			else if (!new_edge_east(data, x, y))
				return (0);
		}
		else if (!new_edge_east(data, x, y))
			return (0);
	}
	else
		map[y][x].edges[EAST] = -1;
	return (1);
}

short find_edge_west(t_data *data, int x, int y)
{
	t_box **map;

	map = data->map;
	if (x - 1 > 0 && map[y][x - 1].value == 0)
	{

		if (y - 1 > 0 && map[y - 1][x].value == 1)
		{
			if (map[y - 1][x].edges[WEST] >= 0)
			{
				printf("lol\n");
				map[y][x].edges[WEST] = map[y - 1][x].edges[WEST];
				printf("ca casse\n");
				data->edges[map[y][x].edges[WEST]].end.y = (y + 1) * 16;
				printf("==========EDGE GIVEN==============\n");
			}
			else if (!new_edge_west(data, x, y))
				return (0);
		}
		else if (!new_edge_west(data, x, y))
			return (0);
	}
	else
		map[y][x].edges[WEST] = -1;
	return (1);
}

short find_edges(t_data *data)
{
	int x;
	int y;

	y = 0;
	printf("X:%d, Y:%d\n", data->mapSize.x, data->mapSize.y);
	while (y < data->mapSize.y)
	{
		x = 0;
		while (x < data->mapSize.x)
		{
			printf("Number of edges: %d\n", data->edge_nb);
			printf("x:%d, y:%d, value:%d\n", x, y, data->map[y][x].value);
			if (data->map[y][x].value == 1)
			{
				if (!find_edge_north(data, x, y))
				{
					printf("wtf\n");
					return (0);
				}
				printf("north clear\n");
				if (!find_edge_south(data, x, y))
				{
					printf("wtf\n");
					return (0);
				}
				printf("south clear\n");
				if (!find_edge_east(data, x, y))
				{
					printf("wtf\n");
					return (0);
				}
				printf(" east clear\n");
				if (!find_edge_west(data, x, y))
				{
					printf("wtf\n");
					return (0);
				}
				printf(" west clear\n");
			}
			x++;
		}
		y++;

		printf("sortie\n");
	}
	return (1);
}
