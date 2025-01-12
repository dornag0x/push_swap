/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:55:43 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 23:01:11 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	indexer(t_listps *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	pusher(t_stack *stack_a, int *nums)
{
	t_listps	*tmp;
	int			i;

	i = 0;
	list_nurs(stack_a);
	while (nums[i])
	{
		tmp = ps_lstnew(nums[i], 0);
		if (!tmp)
			return ;
		ps_lstadd_back(stack_a->data, tmp);
		i++;
	}
	indexer(*stack_a->data);
	stack_a->args_n = ps_lstsize(*stack_a->data);
}
