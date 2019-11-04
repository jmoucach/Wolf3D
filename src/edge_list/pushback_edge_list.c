/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_edge_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:09:35 by jmoucach          #+#    #+#             */
/*   Updated: 2019/11/01 16:54:12 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void			print_edge_list(t_edge_list *edges)
{
	t_edge_list	*first;

	if (edges)
	{
		first = edges;
		while (edges)
		{
			printf("id:%d\nstart:x:%d, y:%d\nend:x:%d, y:%d\n",
				(edges)->id, (edges)->edge.start.x, (edges)->edge.start.y,
				(edges)->edge.end.x, (edges)->edge.end.y);
			edges = (edges)->next;
		}
		edges = first;
	}
}

void			pushback_edge(t_edge_list **edges, t_edge_list *edge)
{
	t_edge_list	*first;

	first = *edges;
	while ((*edges)->next)
		*edges = (*edges)->next;
	edge->next = NULL;
	(*edges)->next = edge;
	*edges = first;
}
