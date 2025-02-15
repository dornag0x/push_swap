/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:20:22 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 12:24:34 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_listps	*ps_lstcpy(t_listps *stack)
{
	t_listps	*cpy;
	t_listps	*tmp;
	t_listps	*head;

	cpy = NULL;
	head = stack;
	while (head)
	{
		tmp = ps_lstnew(head->num, head->norma);
		tmp->index = head->index;
		ps_lstadd_back(&cpy, tmp);
		head = head->next;
	}
	return (cpy);
}
