/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:50:27 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/24 16:33:08 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

/*static void revert_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->args_n > 0)
		pushh(stack_b, stack_a);
}

void	big_algoA(t_stack *stack_a, t_stack *stack_b)
{
	int bit;
	int size;
	int max_bits;
	t_listps *tmp;

	size = stack_a->size;
	max_bits = 0;
	while (size > 1)
	{
		size /= 2;
		max_bits++;
	}
	bit = 0;
	while (bit < max_bits)
	{
		cpy = int_sort(*stack_a->data);
		tmp = cpy;
		size = stack_a->args_n;
		while (size-- > 0)
		{
			if (((tmp->num >> bit) & 1) == 1)
				rotatee(stack_a);
			else
				pushh(stack_a, stack_b);
			tmp = tmp->next;
		}
		revert_stack(stack_a, stack_b);
		bit++;
	}
}*/
