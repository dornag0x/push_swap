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

static void revert_stack(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->args_n > 0)
        pushh(stack_b, stack_a);
}

void	big_algoA(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
    int bit;
    int size;
	int i;
    int max_bits;
    t_listps *tmp;

	size = stack_a->args_n;
	while (size > 1 && ++max_bits)
		size /= 2;
	i = -1;
    while (++i <= max_bits)
    {
        size = stack_a->args_n;
        while (size-- && valid_data(*stack_a->data))
        {
            if ((((*stack_a->data)->num >> bit) & 1) == 1)
                rotatee(stack_a);
            else
                pushh(stack_a, stack_b);
        }
        revert_stack(stack_a, stack_b);
    }
}

