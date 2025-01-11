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

void	rev_rotatee(t_stack *stack)
{
	t_listps	*tmp;
	t_listps	*last;

	last = ps_lstlast(*stack->data);
	tmp = ps_lstnew(last->num, last->index);
	ps_lstadd_front(stack->data, tmp);
	ps_lstclear_last(*stack->data);
}
