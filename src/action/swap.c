/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 14:11:05 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swapp(t_stack *stack, int s)
{
	t_listps	*tmp;
	t_listps	*next;

	if (!stack || !stack->head || !stack->head->next)
		err_handle(ERR_NULL);
	tmp = stack->head->next;
	stack->head->next = tmp->next;
	next = ps_lstcpy(tmp);
	next->next = stack->head;
	stack->head = next;
	free(tmp);
	stack->tails = ps_lstlast(stack->head);
	if (s == 1)
		ft_printf("sa\n");
	else if (s == 2)
		ft_printf("sb\n");
}
