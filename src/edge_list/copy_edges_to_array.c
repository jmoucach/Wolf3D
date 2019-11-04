/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_edges_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:11:26 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 16:47:10 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

short			copy_edges_to_array(t_data *data, t_edge_list *edges)
{
	int			i;
	t_edge_list	*first;

	i = 0;
	first = edges;
	if (!(data->edges = (t_edge*)malloc(sizeof(t_edge) * data->edge_nb)))
		return (0);
	while (i < data->edge_nb)
	{
		data->edges[i].start.x = edges->edge.start.x;
		data->edges[i].start.y = edges->edge.start.y;
		data->edges[i].end.x = edges->edge.end.x;
		data->edges[i].end.y = edges->edge.end.y;
		i++;
		edges = edges->next;
	}
	edges = first;
	return (1);
}
