/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/05 23:55:42 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	valid_data(t_listps	*data)
{
	t_listps	*nxt;

	nxt = data->next;
	while (nxt)
	{
		if (nxt->num < data->num)
			return (0);
		nxt = nxt->next;
		data = data->next;
	}
	return (1);
}

void	iterlist(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*head;
	t_listps	*pivot;
	int			i;

	head = *stack_a->data;
	pivot = ps_lstlast(*stack_a->data);
	i = 0;
	while (head->next)
	{
		if (head->num > pivot->num)
		{
			while (*stack_a->data != head)
			{
				rotatee(stack_a);
				i++;
			}
			pushh(stack_a, stack_b);
			while (i > 0)
			{
				rev_rotatee(stack_a);
				i--;
			}
			head = *stack_a->data;
			pivot = ps_lstlast(*stack_a->data);
		}
		else
			head = head->next;
	}	
}

char	*controller(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*pivot;
	t_listps	*index;
	t_listps	*head;
	char		*instr;
	int			i;

	index = *stack_a->data;
	stack_a->check = false;
	pivot = ps_lstlast(*stack_a->data);
	iterlist(stack_a, stack_b);
	if (stack_a->data)
	{
		printf("stack A: \n");
		print_test(stack_a);
	}
	if (stack_b->data)
	{
		printf("stack B: \n");
		print_test(stack_b);
	}
}
