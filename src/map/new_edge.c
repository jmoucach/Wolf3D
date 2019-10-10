/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:55:50 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/10 19:30:06 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void copy_edge_data(t_edge **tmp, t_edge *edge, int i)
{
	(*tmp)[i].start.x = edge[i].start.x;
	(*tmp)[i].start.y = edge[i].start.y;
	(*tmp)[i].end.x = edge[i].end.x;
	(*tmp)[i].end.y = edge[i].end.y;
}

short new_edge_north(t_data *data, int x, int y)
{
	t_edge *tmp;
	int i;

	i = -1;
	tmp = NULL;
	data->edge_nb++;
	if (data->edges == NULL)
	{
		if (!(data->edges = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
			return (0);
		else
		{
			data->edges[0].start.x = (16 * x);
			data->edges[0].start.y = (16 * y);
			data->edges[0].end.x = (16 * (x + 1));
			data->edges[0].end.y = (16 * y);
		}	printf("blop north\n");
	}
	else
	{
		realloc_edge(data);
		// if (!(tmp = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
		// 	return (0);
		// // while (++i < data->edge_nb - 1)
		// 	// copy_edge_data(&tmp, data->edges, i);
		// 	ft_memcpy(tmp, data->edges, data->edge_nb - 1);
		// ft_memdel((void**)&(data->edges));
		// // free(data->edges);
		// printf("here north\n");
		// tmp[data->edge_nb].start.x = (16 * x);
		// tmp[data->edge_nb].start.y = (16 * y);
		// tmp[data->edge_nb].end.x = (16 * (x + 1));
		// tmp[data->edge_nb].end.y = (16 * y);
		// printf("ca casse ici\n");
		// data->edges = tmp;
	}
	data->map[y][x].edges[NORTH] = data->edge_nb;
	printf("end north\n");
	return (1);
}

short new_edge_south(t_data *data, int x, int y)
{
	t_edge *tmp;
	int i;

	i = -1;
	data->edge_nb++;
	tmp = NULL;
	if (data->edges == NULL)
	{
		if (!(data->edges = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
			return (0);
		else
		{
			data->edges[0].start.x = (16 * x);
			data->edges[0].start.y = (16 * (y + 1));
			data->edges[0].end.x = (16 * (x + 1));
			data->edges[0].end.y = (16 * (y + 1));
		}	printf("blop south\n");
	}
	else
	{
		realloc_edge(data);
		// if (!(tmp = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
		// 	return (0);
		// // while (++i < data->edge_nb - 1)
		// 	ft_memcpy(tmp, data->edges, data->edge_nb - 1);
		// 	//copy_edge_data(&tmp, data->edges, i);
		// printf("here south\n");
		// // free(data->edges);
		// ft_memdel((void**)&(data->edges));
		// printf("flex\n");
		// tmp[data->edge_nb].start.x = (16 * x);
		// tmp[data->edge_nb].start.y = (16 * (y + 1));
		// tmp[data->edge_nb].end.x = (16 * (x + 1));
		// tmp[data->edge_nb].end.y = (16 * (y + 1));
		// printf("ca casse ici\n");
		// data->edges = tmp;
	}
	data->map[y][x].edges[SOUTH] = data->edge_nb;
	printf("end south\n");
	return (1);
}

short new_edge_east(t_data *data, int x, int y)
{
	t_edge *tmp;
	int i;

	i = -1;
	data->edge_nb++;
	tmp = NULL;
	if (data->edges == NULL)
	{
		if (!(data->edges = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
			return (0);
		else
		{
			data->edges[0].start.x = (16 * (x + 1));
			data->edges[0].start.y = (16 * y);
			data->edges[0].end.x = (16 * (x + 1));
			data->edges[0].end.y = (16 * (y + 1));
		}	printf("blop east\n");
	}
	else
	{
		realloc_edge(data);
	// 	if (!(tmp = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
	// 		return (0);
	// 	// while (++i < data->edge_nb - 1)
	// 	// 	copy_edge_data(&tmp, data->edges, i);
	// 		ft_memcpy(tmp, data->edges, data->edge_nb - 1);
	// 	printf("here east\n");
	// 	// free(data->edges);
	// 	ft_memdel((void**)&(data->edges));
	// 	printf("flex\n");
	// 	tmp[data->edge_nb].start.x = (16 * (x + 1));
	// 	tmp[data->edge_nb].start.y = (16 * y);
	// 	tmp[data->edge_nb].end.x = (16 * (x + 1));
	// 	tmp[data->edge_nb].end.y = (16 * (y + 1));
	// 	printf("ca casse ici\n");

	// 	data->edges = tmp;
	}
	data->map[y][x].edges[EAST] = data->edge_nb;
	printf("end east\n");
	return (1);
}

short new_edge_west(t_data *data, int x, int y)
{
	t_edge *tmp;
	int i;

	i = -1;
	tmp = NULL;
	data->edge_nb++;
	if (data->edges == NULL)
	{
		if (!(data->edges = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
			return (0);
		else
		{
			data->edges[0].start.x = (16 * x);
			data->edges[0].start.y = (16 * y);
			data->edges[0].end.x = (16 * x);
			data->edges[0].end.y = (16 * (y + 1));
		}
		printf("blop west\n");
	}
	else
	{
		realloc_edge(data);
		// if (!(tmp = (t_edge *)malloc(sizeof(t_edge) * data->edge_nb)))
		// 	return (0);
		// // while (++i < data->edge_nb)
		// // 	copy_edge_data(&tmp, data->edges, i);
		// 	ft_memcpy(tmp, data->edges, data->edge_nb - 1);

		// printf("here west\n");
		// ft_memdel((void**)&(data->edges));
		// // free(data->edges);
		// printf("flex\n");
		// tmp[data->edge_nb].start.x = (16 * x);
		// tmp[data->edge_nb].start.y = (16 * y);
		// tmp[data->edge_nb].end.x = (16 * x);
		// tmp[data->edge_nb].end.y = (16 * (y + 1));
		// printf("ca casse ici\n");
		// data->edges = tmp;
	}
	data->map[y][x].edges[WEST] = data->edge_nb;
	printf("end west\n");
	return (1);
}
