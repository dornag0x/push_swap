/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:11 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:10:13 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	pushh(t_stack *stack_1, t_stack *stack_2)
{
	t_listps	*tmp;
	t_listps	*head;
	t_listps	*next;

	tmp = *stack_1->data;
	head = ps_lstnew(tmp->num);
	if (!stack_2->data)
		init_b(stack_2, tmp->num);
	else
		ps_lstadd_front(stack_2->data, head);
	next = tmp->next;
	*stack_1->data = (*stack_1->data)->next;
	free(tmp);
}
