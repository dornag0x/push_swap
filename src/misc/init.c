/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:55:43 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 15:19:41 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tails = NULL;
	stack->size = 0;
}

static int	indexer(t_listps *head)
{
	t_listps	*current;
	int			i;

	current = head;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
	return (i);
}

void	pusher(t_stack *stack_a, t_stack *stack_b, char **nums)
{
	int			i;

	if (!stack_a || !nums)
		err_handle(ERR_NULL);
	i = 0;
	stack_a->head = lister(nums);
	if (!stack_a->head)
		return ;
	stack_a->tails = ps_lstlast(stack_a->head);
	stack_a->size = indexer(stack_a->head);
	check_arg(stack_a->head);
	init_stack(stack_b);
}
