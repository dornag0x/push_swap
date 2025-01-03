/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/03 18:23:50 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	controller(t_stack *stack_a, t_stack *stack_b)
{
	t_listps	*pivot;
	int			i;
	bool		ver;

	i = 0;
	ver = false;
	swapp(stack_a);
	print_test(stack_a);
}
