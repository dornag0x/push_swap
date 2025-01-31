/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:55:43 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 23:01:11 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	indexer(t_listps *head)
{
	t_listps	*current;
	int			i;

	current = head;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tails = NULL;
	stack->size = 0;
	stack->check = false;
}

void	pusher(t_stack *stack_a, int *nums)
{
	t_listps	*new_node;
	int			i;

	if (!stack_a || !nums)
		return ;
	init_stack(stack_a);
	i = 0;
	while (nums[i] != NULL)
	{
		new_node = ps_lstnew(nums[i]);
		if (!new_node)
			return ;
		if (stack_a->tails == NULL)
		{
			stack_a->head = new_node;
			stack_a->tails = new_node;
		}
		else
		{
			new_node->prev = stack_a->tails;
			stack_a->tails->next = new_node;
			stack_a->tails = new_node;
		}
		stack_a->size++;
		i++;
	}
	indexer(stack_a->head);
}
