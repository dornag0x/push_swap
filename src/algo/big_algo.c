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
	t_listps	*head;
	t_listps	*tmp;

	head = stack;
	tmp = head->next;
	while (tmp->next)
	{
		if (tmp->norma > tmp->next->norma)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	find_max(t_listps *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->num > i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}

static int	get_max_bits(t_listps *stack)
{
	int	max;
	int	bits;

	max = find_max(stack);
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix_sort_b(t_stack *stack_b, t_stack *stack_a, int i, int max_bits)
{
	int			size;
	t_listps	*current;

	size = stack_b->size;
	while (size-- && i <= max_bits && !is_sorted(stack_a->head))
	{
		current = stack_b->head;
		if (((current->norma >> i) & 1) == 0)
			rotatee(stack_b, 2);
		else
			pushh(stack_b, stack_a, 1);
	}
	if (is_sorted(stack_a->head))
	{
		while (stack_b->size)
			pushh(stack_b, stack_a, 1);
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	size;

	size = stack_a->size;
	max_bits = get_max_bits(stack_a->head);
	i = -1;
	while (++i <= max_bits && !is_sorted(stack_a->head))
	{
		size = stack_a->size;
		while (size--)
		{
			if (((stack_a->head->norma >> i) & 1) == 0)
				pushh(stack_a, stack_b, 2);
			else
				rotatee(stack_a, 1);
		}
		radix_sort_b(stack_b, stack_a, i + 1, max_bits);
	}
}
