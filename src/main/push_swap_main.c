/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:30:54 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 19:47:17 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void	printstack(t_listps *s)
// {
// 	while (s)
// 	{
// 		printf("%d\n", s->num);
// 		s = s->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_listps	*tmp;

	if (argc == 1)
		err_handle(ERR_ARG);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		err_handle(ERR_ALLOC);
	pusher(stack_a, stack_b, argv);
	if (!(stack_a->head))
	{
		write(2, "Error\n", 6);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	controller(stack_a, stack_b);
	// printstack(stack_a->head);
	while (stack_a && stack_a->head)
	{
		tmp = stack_a->head->next;
		free(stack_a->head);
		stack_a->head = tmp;
	}
	free(stack_a);
	free(stack_b);
}
