/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:01 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/30 22:27:56 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	pusher(t_stack *stack_a, t_stack *stack_b, int *nums)
{
	t_listps	*tmp;
	int			i;

	i = 0;
	while (nums[i])
	{
		tmp = ps_lstnew(nums[i]);
		if (!tmp)
			return ;
		ps_lstadd_back(&stack_a->num, tmp);
		i++;
	}

}
