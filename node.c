/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:39:29 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/06/13 19:25:52 by ssaadaou         ###   ########.fr       */
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
// int main()
// {
//     list_t *head = NULL;
//     list_t *node1 = new_node(12);
//     list_t *node2 = new_node(14);
//     add_node_top(&head , node1);
//     add_node_top(&head , node2);
//     while(head != NULL)
//     {
//         printf("%d\n", head->data);
//         head = head->link;
//     }
// }