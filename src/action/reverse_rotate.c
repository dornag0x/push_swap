/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:10:19 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	rev_rotatee(t_stack *stack, int s)
{
	t_listps	*tmp;
	t_listps	*last;

	tmp = stack->head;
	while (tmp->next && tmp->next != stack->tails)
		tmp = tmp->next;
	last = stack->tails;
	tmp->next = NULL;
	stack->tails = tmp;
	last->next = stack->head;
	stack->head = last;
	if (s == 1)
		ft_printf("rra\n");
	if (s == 2)
		ft_printf("rrb\n");
}
