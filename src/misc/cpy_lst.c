/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:45:52 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/11 10:29:21 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

t_listps	*to_dec(t_listps *lst)
{
	t_listps	*head;
	int			i;

	head = lst;
	i = 0;
	while (head)
	{
		head->num = i;
		head = head->next;
		i++;
	}
	return (lst);
}

t_listps *idx_sort(t_listps *stack)
{
	t_listps	*head;
	t_listps	*pol;
	int			i_tmp;
	int			l_tmp;

	i_tmp = 0;
	l_tmp = 0;
	head = stack;
	while (head)
	{
		pol = head->next;
		while (pol)
		{
			if (pol->index < head->index)
			{
				i_tmp = head->num;
				l_tmp = head->index;
				head->num = pol->num;
				head->index = pol->index;
				pol->num = i_tmp;
				pol->index = l_tmp;
			}
			pol = pol->next;
		}
		head = head->next;
	}
	return (stack);
}

t_listps *num_sort(t_listps *stack)
{
	t_listps	*head;
	t_listps	*pol;
	int			i_tmp;
	int			l_tmp;

	i_tmp = 0;
	l_tmp = 0;
	if (!stack || !stack->next)
		return (stack);
	head = stack;
	while (head)
	{
		pol = head->next;
		while (pol)
		{
			if (pol->num < head->num)
			{
				i_tmp = head->num;
				l_tmp = head->index;
				head->num = pol->num;
				head->index = pol->index;
				pol->num = i_tmp;
				pol->index = l_tmp;
			}
			pol = pol->next;
		}
		head = head->next;
	}
	return (stack);
}

t_listps	*int_sort(t_listps *stack)
{
	t_listps	*cpy;

	cpy = ps_lstcpy(stack);
	cpy = num_sort(cpy);
	cpy = to_dec(cpy);
	cpy = idx_sort(cpy);
	return (cpy);
}
