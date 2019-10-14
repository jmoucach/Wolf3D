/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_edge_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:17:26 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/12 17:58:46 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

t_edge_list *create_edge_list(int x1, int y1, int x2, int y2, int id)
{
	t_edge_list *edge_list;

	if (!(edge_list = (t_edge_list *)malloc(sizeof(t_edge_list))))
		return (NULL);
		edge_list->id = id;
	edge_list->edge.start.x = x1;
	edge_list->edge.start.y = y1;
	edge_list->edge.end.x = x2;
	edge_list->edge.end.y = y2;
	edge_list->next = NULL;
	return (edge_list);
}
