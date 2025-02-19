/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 20:24:45 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void    rev_rotatee(t_stack *stack, int s)
{
	t_listps    *tmp;
    t_listps    *last;
	
    if (!stack || !stack->head || !stack->head->next)
        err_handle(ERR_NULL);
    if (stack->head->next == stack->tails)
    {
        swapp(stack, s);
        return;
    }
    tmp = stack->head;
    while (tmp->next != stack->tails)
        tmp = tmp->next;
    last = stack->tails;
    tmp->next = NULL;
    stack->tails = tmp;
    last->next = stack->head;
    stack->head = last;

    if (s == 1)
        ft_printf("rra\n");
    else if (s == 2)
        ft_printf("rrb\n");
}
