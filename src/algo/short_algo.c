/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:13:20 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 21:42:04 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

static int	getMin(t_stack *stack)
{
	t_listps	*head;
	t_listps	*tmp;

	tmp = stack->head;
	head = stack->head;
	while (tmp)
	{
		if (tmp->num < head->num)
			head = tmp;
		tmp = tmp->next;
	}
	return (head->index);
}

void	alg_2(t_stack *stack)
{
	if (stack->head->num > stack->head->next->num)
		swapp(stack, 1);
}

void	alg_3(t_stack *stack)
{
	t_listps	*head;
	t_listps	*tail;

	tail = ps_lstlast(stack->head);
	if (tail->num < stack->head->num)
		rotatee(stack, 1);
	head = stack->head->next;
	if (stack->head->num > head->num)
		swapp(stack, 1);
	tail = ps_lstlast(stack->head);
	head = stack->head->next;
	if (head->num > tail->num)
	{
		rev_rotatee(stack, 1);
		swapp(stack, 1);
	}
}

void	alg_4(t_stack *stack_a, t_stack *stack_b)
{
	int			index;

	index = getMin(stack_a);
	while (stack_a->head->index != index)
		rotatee(stack_a, 1);
	pushh(stack_a, stack_b, 2);
	alg_3(stack_a);
	pushh(stack_b, stack_a, 1);
}

void	alg_5(t_stack *stack_a, t_stack *stack_b)
{
	int			index;

	index = getMin(stack_a);
	while (stack_a->head->index != index)
		rotatee(stack_a, 1);
	pushh(stack_a, stack_b, 2);
	alg_4(stack_a, stack_b);
	pushh(stack_b, stack_a, 1);
}
