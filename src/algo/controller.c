/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/11 10:56:16 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	valid_data(t_listps *data)
{
	if (!data)
		return (1);
	while (data->next)
	{
		if (data->num > data->next->num)
			return (0);
		data = data->next;
	}
	return (1);
}

char	*controller(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*cpy;
	t_listps	*pivot;
	t_listps	*index;
	t_listps	*head;
	char		*instr;
	int			i;

	index = *stack_a->data;
	stack_a->check = false;
	if (count_list(stack_a) == 2)
		alg_2(stack_a);
	if (count_list(stack_a) == 3)
		alg_3(stack_a);
	else
	{
		cpy = int_sort(*stack_a->data);
		//while (!valid_data(*stack_a->data))
		big_algo(stack_a, stack_b, cpy);
		cpy = int_sort(*stack_a->data);
		big_algo(stack_a, stack_b, cpy);
	}
	//if (count_list(stack_a) == 4)
	//	alg_4(stack_a);
	//pivot = ps_lstlast(*stack_a->data);
	//iterlist(stack_a, stack_b);
	//n_iterlist(stack_a, stack_b);
	if (stack_a->data)
	{
		printf("stack A: \n");
		print_test(stack_a);
	}
	/*if (stack_b->data)
	{
		printf("stack B: \n");
		print_test(stack_b);
	}*/
}
