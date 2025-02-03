/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:30:54 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/03 15:41:30 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*n_argv;

	if (argc <= 2)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b || !stack_a)
		err_handle(ERR_ALLOC);
	n_argv = super_atoi(argv);
	check_arg(n_argv);
	pusher(stack_a, stack_b, n_argv);
	free(n_argv);
	controller(stack_a, stack_b);
}
