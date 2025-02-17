/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:25:55 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/17 15:41:49 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ps_lstcmp(t_listps *stack, int n)
{
	t_listps	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->num == n)
			return (tmp->num);
		tmp = tmp->next;
	}
	return (0);
}

static int	iterator(t_listps *cpy)
{
	int			i;

	i = cpy->num;
	while (cpy)
	{
		if (cpy->num < i)
			i = cpy->num;
		cpy = cpy->next;
	}
	return (i);
}

static void	sorter(t_listps *stack, int *tmp, int size)
{
	int	i;
	int	ind;

	i = iterator(stack);
	ind = 0;
	while (ind < size)
	{
		if (ps_lstcmp(stack, i))
		{
			tmp[ind] = ps_lstcmp(stack, i);
			ind++;
			i++;
		}
		else
			i++;
	}
}

void	normalizer(t_listps *stack, int size)
{
	int			*tmp;
	int			i;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	sorter(stack, tmp, size);
	while (stack)
	{
        i = 0;
        while (tmp[i])
        {
            if (tmp[i] == stack->num)
                stack->norma = i;
            i++;
        }
        stack = stack->next;
	}
}