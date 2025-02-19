/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:25:55 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/18 17:24:42 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_lst(int *lst, int size)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (lst[j] < lst[i])
			{
				res = lst[i];
				lst[i] = lst[j];
				lst[j] = res;
			}
			j++;
		}
		i++;
	}
}

static void	sorter(t_listps *stack, int *tmp, int size)
{
	long	i;

	i = 0;
	while (i < size)
	{
		tmp[i] = stack->num;
		stack = stack->next;
		i++;
	}
	sort_lst(tmp, size);
}

void	normalizer(t_listps *stack, int size)
{
	int			*tmp;
	int			i;
	t_listps	*head;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	sorter(stack, tmp, size);
	head = stack;
	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (tmp[i] == stack->num)
			{
				stack->norma = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
	free(tmp);
	stack = head;
}
