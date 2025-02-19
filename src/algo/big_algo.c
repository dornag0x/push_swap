/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:50:27 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 20:25:19 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_sorted(t_listps *stack)
{
	int			i;
	t_listps	*head;
	t_listps	*tmp;

	i = 0;
	head = stack;
	tmp = head->next;
	while (tmp->next)
	{
		if (tmp->next->num <= tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	find_max(t_listps *stack)
{
	int i;
	
	i = 0;
	while (stack)
	{
		if (stack->num > i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}

static int get_max_bits(t_listps *stack)
{
	int max;
	int bits;

	max = find_max(stack);
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int 		max_bits;
	int 		i;
	int 		j;
	int			size;
	t_listps	*current;

	i = 0;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a->head);
	while (i < max_bits && !is_sorted(stack_a->head))
	{
		j = 0;
		while (j < size)
		{
			current = stack_a->head;
			if (((current->norma >> i) & 1) == 1)
				rotatee(stack_a, 1);
			else
				pushh(stack_a, stack_b, 2);
			j++;
		}
		while (stack_b->head)
		{
			current = stack_b->head;
			if (((current->norma >> i) & 1) == 1)
				rotatee(stack_b, 1);
			else
				pushh(stack_b, stack_a, 1);
		}
		i++;
	}
}
