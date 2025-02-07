/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:11:41 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:11:43 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

t_listps	*ps_lstnew(int num)
{
	t_listps	*node;

	node = malloc(sizeof(t_listps));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}
