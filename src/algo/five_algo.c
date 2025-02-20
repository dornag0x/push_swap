/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:04:29 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 13:07:05 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	transfer_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;
	int	push_count;

	push_count = 0;
	while (push_count < 2)
	{
		min_idx = get_min(stack_a);
		if (min_idx <= stack_a->size / 2)
		{
			while (stack_a->head->index != min_idx)
				rotatee(stack_a, 1);
		}
		else
		{
			while (stack_a->head->index != min_idx)
				rev_rotatee(stack_a, 1);
		}
		pushh(stack_a, stack_b, 2);
		push_count++;
	}
}

void	final_sort_and_transfer(t_stack *stack_a, t_stack *stack_b)
{
	alg_3(stack_a);
	pushh(stack_b, stack_a, 1);
	pushh(stack_b, stack_a, 1);
}

void	alg_5(t_stack *stack_a, t_stack *stack_b)
{
	transfer_min_to_b(stack_a, stack_b);
	final_sort_and_transfer(stack_a, stack_b);
}
