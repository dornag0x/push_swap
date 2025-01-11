/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:50:27 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/11 10:56:15 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	big_algo(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
	static int	bit = 1;
	t_listps	*pivot;

	if (!(bit == 1))
		bit += bit;
	while (cpy)
	{
		if (!(bit & cpy->num))
			pushh(stack_a, stack_b);
		rotatee(stack_a);
		cpy = cpy->next;
	}
	while ((*stack_b->data))
		pushh(stack_b, stack_a);
}
