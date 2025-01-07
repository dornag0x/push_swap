/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 21:41:47 by hfeufeu          ###   ########.fr       */
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

void	n_iterlist(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*head;
	t_listps	*tail_a;

	tail_a = ps_lstlast(*stack_a->data);
	head = *stack_b->data;
	while ((*stack_b->data)->next)
	{
		if ((*stack_b->data)->num > tail_a->num)
		{
			pushh(stack_b, stack_a);
			rotatee(stack_a);
		}
		else
		{
			rev_rotatee(stack_a);
			pushh(stack_b, stack_a);
			rotatee(stack_a);
			rotatee(stack_a);
		}
		tail_a = ps_lstlast(*stack_a->data);
	}
}

void rad(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*trav;
	int			rad;
	int			cpy;

	trav = *stack_a->data;
	rad = 10;
	while ((*stack_a->data)->next)
	{
		cpy = (*stack_a->data)->num;
		cpy /= rad;
		cpy %= 10;
		rotatee(stack_a);
		rad *= 10;
	}
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
	if (count_list(stack_a) == 2)
		alg_2(stack_a);
	if (count_list(stack_a) == 3)
		alg_3(stack_a);
	if (count_list(stack_a) == 4)
		alg_4(stack_a);
	//pivot = ps_lstlast(*stack_a->data);
	//iterlist(stack_a, stack_b);
	//n_iterlist(stack_a, stack_b);
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
