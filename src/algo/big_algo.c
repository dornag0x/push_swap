/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:50:27 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/11 10:56:15 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

/*void	revert(t_stack *stack_a, t_stack *stack_b)
{
	while ((*stack_b->data)->next)
		pushh(stack_b, stack_a);
	pushh(stack_b, stack_a);
}

void	big_algoB(t_stack *stack_a, t_stack *stack_b, int bit, int max_bits)
{
	int size;
	int i;

	size = stack_b->args_n;
	i = 0;
	while (i < size && bit <= max_bits && !valid_data(*stack_a->data))
	{
		if (((*stack_b->data)->num >> bit) & 1)
			pushh(stack_b, stack_a);
		else
			rotatee(stack_b);
		i++;
	}
	if (valid_data(*stack_a->data))
	{
		while (stack_b->args_n > 0)
			pushh(stack_b, stack_a);
	}
}

void	big_algoA(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
	int			bit;
	int			i;
	int			size;
	int			max_bits;

	i = 0;
	bit = 0;
	size = stack_a->args_n;
	max_bits = sizeof(int) * 8;
	while (size > 1)
	{
		size /= 2;
		bit++;
	}
	while (i <= bit)
	{
		size = stack_a->args_n;
		while (!valid_data(*stack_a->data) && size--)
		{
			if (!(((*stack_a->data)->num >> i) & 1))
				pushh(stack_a, stack_b); 
			else
				rotatee(stack_a);
		}
		big_algoB(stack_a, stack_b, bit, max_bits);
		i++;
	}
	revert(stack_a, stack_b);
}*/

void revert(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->args_n > 0)
        pushh(stack_b, stack_a);
}

void big_algoB(t_stack *stack_a, t_stack *stack_b, int bit, int max_bits)
{
    int size;
    int i;

    size = stack_b->args_n;
    i = 0;
    while (i < size && bit <= max_bits && !valid_data(*stack_a->data))
    {
        if (((*stack_b->data)->num >> bit) & 1)
            pushh(stack_b, stack_a);
        else
            rotatee(stack_b);
        i++;
    }
    if (valid_data(*stack_a->data))
    {
        while (stack_b->args_n > 0)
            pushh(stack_b, stack_a);
    }
}

void big_algoA(t_stack *stack_a, t_stack *stack_b, t_listps *cpy)
{
    int bit = 0;
    int size = stack_a->args_n;
    int max_bits = 0;

    t_listps *tmp = *stack_a->data;
    int max_value = 0;
    while (tmp)
    {
        if (tmp->num > max_value)
            max_value = tmp->num;
        tmp = tmp->next;
    }
    while (max_value > 0)
    {
        max_value /= 2;
        max_bits++;
    }
    while (bit < max_bits)
    {
        size = stack_a->args_n;
        while (!valid_data(*stack_a->data) && size--)
        {
            if (!(((*stack_a->data)->num >> bit) & 1))
                pushh(stack_a, stack_b);
            else
                rotatee(stack_a);
        }
        big_algoB(stack_a, stack_b, bit, max_bits);
        bit++;
    }

    revert(stack_a, stack_b);
}
