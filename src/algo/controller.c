/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/17 16:04:17 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int valid_data(t_listps *data)
{
	t_listps *current;

	if (!data)
		err_handle(ERR_NULL);
	current = data;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

void controller(t_stack *stack_a, t_stack *stack_b)
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

