/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/03 18:15:07 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	swapp(t_stack *stack, int s)
{
	t_listps	*head;
	t_listps	*tmp;
	t_listps	*next;

	tmp = stack->head->next;
	next = ps_lstcpy(stack->head->next);
	stack->head->next = stack->head->next->next;
	free(tmp);
	ps_lstadd_front(&stack->head, next);
	if (s == 1)
		printf("sa\n");
	else if (s == 2)
		printf("sb\n");
}
