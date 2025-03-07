/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:13:20 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 13:05:32 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_min(t_stack *stack)
{
	t_listps	*head;
	t_listps	*tmp;

	tmp = stack->head;
	head = stack->head;
	while (tmp)
	{
		if (tmp->norma < head->norma)
			head = tmp;
		tmp = tmp->next;
	}
	return (head->index);
}

void	alg_2(t_stack *stack)
{
	if (stack->head->norma > stack->head->next->norma)
		swapp(stack, 1);
}

void	alg_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->norma;
	b = stack->head->next->norma;
	c = stack->head->next->next->norma;
	if (a > b && b < c && a < c)
		swapp(stack, 1);
	else if (a > b && b > c)
	{
		swapp(stack, 1);
		rev_rotatee(stack, 1);
	}
	else if (a > b && b < c && a > c)
		rotatee(stack, 1);
	else if (a < b && b > c && a < c)
	{
		swapp(stack, 1);
		rotatee(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rev_rotatee(stack, 1);
}

void	alg_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;

	min_idx = get_min(stack_a);
	if (min_idx == 1)
		swapp(stack_a, 1);
	else if (min_idx == 2)
	{
		rotatee(stack_a, 1);
		rotatee(stack_a, 1);
	}
	else if (min_idx == 3)
		rev_rotatee(stack_a, 1);
	pushh(stack_a, stack_b, 2);
	alg_3(stack_a);
	pushh(stack_b, stack_a, 1);
}
