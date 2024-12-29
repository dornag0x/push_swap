/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:01 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/28 19:12:02 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	pusher(t_stack **stack, int to_sort)
{
	t_stack *tmp;

	tmp = ps_lstnew(to_sort);
	ps_lstadd_back(stack, tmp);
	free(tmp);
}
