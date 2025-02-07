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
#include <push_swap.h>

void	rotatee(t_stack *stack, int s)
{
	t_listps	*head;

	head = stack->head;
	stack->head = stack->head->next;
	ps_lstadd_back(&stack->head, head);
	stack->tails = head;
	stack->tails->next = NULL;
	if (s == 1)
		ft_printf("ra\n");
	else if (s == 2)
		ft_printf("rb\n");
}
