/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 16:45:52 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swapp(t_stack *stack, int s)
{
	t_listps	*first;
	t_listps	*second;

	if (!stack || !stack->head || !stack->head->next)
		err_handle(ERR_NULL);
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
	stack->tails = ps_lstlast(stack->head);
	if (s == 1)
		ft_printf("sa\n");
	else if (s == 2)
		ft_printf("sb\n");
}
