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

void revert(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->args_n > 0)
        pushh(stack_b, stack_a);
}

void big_algoA(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
    int bit;
    int size;
    int max_bits;
    t_listps *tmp;
    int max_value;

	bit = 0;
	size = stack_a->args_n;
	max_bits = 0;
	tmp = *stack_a->data;
	max_value = 0;
	while (tmp)
	{
        if (tmp->num > max_value)
            max_value = tmp->num;
        tmp = tmp->next;
    }
	while (max_value > 0)
	{
		max_value /= 2;
		max_bits++;
	}
	while (bit < max_bits && !(valid_data(*stack_a->data)))
	{
		size = stack_a->args_n;
		while (size--)
		{
			if (((cpy->num >> bit) & 1) == 1)
			{
				pushh(stack_a, stack_b);
				cpy = cpy->next;
			}
			else
			{
				rotatee(stack_a);
				cpy = cpy->next;
			}
		}
		bit++;
		revert(stack_a, stack_b);
		cpy = int_sort(*stack_a->data);
    }
}
