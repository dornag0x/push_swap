/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:27:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 17:43:50 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	free_and_exit(t_stack *s_a, t_stack *s_b)
{
	t_listps	*tmp;
	t_listps	*head;

	tmp = s_a->head;
	head = s_a->head;
	write(2, "Error\n", 6);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(s_a);
	free(s_b);
	exit(EXIT_FAILURE);
}

void	check_arg(t_stack *s_a, t_stack *s_b)
{
	t_listps	*tmp;
	t_listps	*next;
	t_listps	*head;

	tmp = s_a->head;
	head = s_a->head;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (next->num == tmp->num)
				free_and_exit(s_a, s_b);
			next = next->next;
		}
		tmp = tmp->next;
	}
}
