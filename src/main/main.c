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
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *tmp;
	int		i;
	int num;

	if (argc <= 2)
		return 0;
	tmp = NULL;
	i = 2;
	num = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		tmp = ps_lstnew(num);
		ps_lstadd_back(stack_a, tmp);
		free(tmp);
		i++;
	}
}
