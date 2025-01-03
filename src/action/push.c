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

void	pushh(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*head;

	if (!stack_b->data)
		list_nurs(stack_b);
	if (!stack_a->data)
		list_nurs(stack_a);
	head = *stack_a->data;
	ps_lstadd_front(stack_b->data, head);
}
