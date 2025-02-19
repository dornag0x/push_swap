/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:11 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 18:21:29 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    pushh(t_stack *stack_1, t_stack *stack_2, int s)
{
	t_listps    *tmp;

	if (!stack_1 || !stack_1->head || !stack_2)
		err_handle(ERR_NULL);
	tmp = stack_1->head;
	stack_1->head = stack_1->head->next;
	if (stack_1->head == NULL)
        stack_1->tails = NULL;
    tmp->next = stack_2->head;
    stack_2->head = tmp;
    if (!stack_2->tails)
        stack_2->tails = tmp;
    stack_1->size--;
    stack_2->size++;
    if (s == 1)
        ft_printf("pa\n");
    else if (s == 2)
        ft_printf("pb\n");
}
