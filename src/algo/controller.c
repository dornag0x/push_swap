/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dornagol <dornagol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 21:46:30 by dornagol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	controller(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*tmp;

	tmp = stack_a->head;
	normalizer(tmp, stack_a->size);
	stack_a->head = tmp;
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
		alg_2(stack_a);
	else if (stack_a->size == 3)
		alg_3(stack_a);
	else if (stack_a->size == 4)
		alg_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		alg_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
