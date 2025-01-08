/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:01 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 23:35:27 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	pusher(t_stack *stack_a, int *nums)
{
	t_listps	*tmp;
	int			i;

	i = 0;
	list_nurs(stack_a);
	while (nums[i])
	{
		tmp = ps_lstnew(nums[i]);
		if (!tmp)
			return ;
		ps_lstadd_back(stack_a->data, tmp);
		i++;
	}
	indexer(*stack_a->data);
}
