/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/30 12:15:00 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int valid_data(t_listps *data)
{
	t_listps *current;

	if (!data)
		return (1);
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
	if (stack_a->size == 2)
		alg_2(stack_a);
	else if (stack_a->size == 3)
		alg_3(stack_a);
	/*else
		big_algoA(stack_a, stack_b);
	if (stack_a->data)
	{
		printf("stack A: \n");
		print_test(stack_a);
	}
	if (stack_b->data)
	{
		printf("stack B: \n");
		print_test(stack_b);
	}*/
	//rev_rotatee(stack_a, 1);
	print_test(stack_a);
	//print_test(stack_b);
	//print_test(stack_b);
}

