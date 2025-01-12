/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:50:27 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/11 10:56:15 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	revert(t_stack *stack_a, t_stack *stack_b)
{
	while ((*stack_b->data)->next)
		pushh(stack_b, stack_a);
	pushh(stack_b, stack_a);
}

/*void	big_algo(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
	static int	bit = 1;
	t_listps	*pivot;

	while (cpy)
	{
		printf("%d\n", bit & cpy->num);
		if (!(bit & cpy->num))
			pushh(stack_a, stack_b);
		else
			rotatee(stack_a);
		cpy = cpy->next;
	}
	revert(stack_a, stack_b);
	bit += bit;
}*/

void	big_algo(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
	int			bit;
	int			i;
	int			size;
	t_listps	*pivot;

	bit = 0;
	size = stack_a->args_n;
	while (!valid_data(*stack_a->data))
	{
		i = 0
		pivot = cpy;
		while (i < size)
		{
			if (!((pivot->num >> bit) & 1))
				pushh(stack_a, stack_b);
			else
				rotatee(stack_a);
			pivot = pivot->next;
			i++;
		}
		revert(stack_a, stack_b);
		bit++;
	}
}
