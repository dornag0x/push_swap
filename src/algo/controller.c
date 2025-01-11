/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/08 01:13:06 by hfeufeu          ###   ########.fr       */
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

void	hand(t_listps *stack)
{
	t_listps	*indx;
	t_listps	*head;
	t_listps	*tmp;

	tmp = NULL;
	indx = stack->next;
	while (stack->next)
	{
		if (indx->num < stack->num)
		{
			tmp = indx;
			indx = stack;
			stack = tmp;
		}
		stack = stack->next;
		indx = stack->next;
	}
}

void	int_sort(t_stack *stack)
{
	t_listps	**cpy;
	t_listps	*head;
	t_listps	*print;
	t_listps	*tmp;

	cpy = ps_lstcpy(stack);
	head = *cpy;
	tmp = malloc(sizeof(t_listps));
	if (!tmp)
		return;
	while (!valid_data(*cpy))
		hand(*cpy);
	print_testlst(cpy);
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
	else
		int_sort(stack_a);
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
	if (stack_b->data)
	{
		printf("stack B: \n");
		print_test(stack_b);
	}
}
