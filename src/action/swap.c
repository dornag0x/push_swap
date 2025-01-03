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

void	swapp(t_stack *stack)
{
	t_listps	*head;
	t_listps	*tmp;
	t_listps	*pivot;
	int			i;

	i = 0;
	head = *stack->data;
	head = head->next;
	tmp = head;
	pivot = ps_lstnew(head->num);
	ps_lstclear2nd(*stack->data);
	ps_lstadd_front(stack->data, pivot);
}
