/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:30:54 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 15:53:31 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_listps	*tmp;

	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(t_stack));
		if (!stack_a)
		err_handle(ERR_ALLOC);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		err_handle(ERR_ALLOC);
	pusher(stack_a, stack_b, argv);
	if (!(stack_a->head))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	controller(stack_a, stack_b);
	while(stack_a && stack_a->head)
	{
		tmp = stack_a->head->next;
		free(stack_a->head);
		stack_a->head = tmp;
	}
	free(stack_a);
	free(stack_b);
}
