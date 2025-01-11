/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:26 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:10:27 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	rotatee(t_stack *stack)
{
	t_listps	*tmp;
	t_listps	*head;

	head = *stack->data;
	tmp = ps_lstnew((*stack->data)->num, (*stack->data)->index);
	*stack->data = (*stack->data)->next;
	ps_lstadd_back(stack->data, tmp);
	free(head);
}
