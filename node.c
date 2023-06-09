/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:39:29 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/06/18 22:39:50 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

list_t *new_node(int num)
{
    list_t *head;

    head = (list_t *)malloc(sizeof(list_t));
    if (!head)
        return NULL;
    head->data = num;
    head->link = NULL;
    return (head);
}
list_t	*last_n(list_t	*stack)
{
	while (stack->link)
		stack = stack->link;
	return (stack);
}
void	add_node_end(list_t **head, list_t *newnode)
{
	list_t	*temp;

	temp = *head;
	if (!*head)
	{
		*head = newnode;
		return ;
	}
	last_n(temp)->link = newnode;
}
void add_node_top(list_t **head, list_t *new_node)
{
    if(!new_node)
        return;
    new_node->link = *head;
    *head = new_node;
}
