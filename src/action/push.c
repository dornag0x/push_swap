/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:11 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/18 17:26:44 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pushh(t_stack *stack_1, t_stack *stack_2, int s)
{
	t_listps	*tmp;
	t_listps	*head;

	tmp = stack_1->head;
	head = ps_lstnew(tmp->num, tmp->norma);
	ps_lstadd_front(&stack_2->head, head);
	stack_1->head = stack_1->head->next;
	//free(tmp);
	if (s == 1)
		ft_printf("pa\n");
	else if (s == 2)
		ft_printf("pb\n");
}
