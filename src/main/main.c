/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:30:54 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/28 11:30:57 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int		err;
	int		i;

	if (argc <= 2)
		return 0;
	if (invalid())
		err_handle(1);
	else 
	{
		while (argv[i])
		{
			pusher(stack_a, argv[i]);
			i++;
		}
	}
}
