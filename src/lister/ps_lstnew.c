/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:11:41 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 12:24:49 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_listps	*ps_lstnew(int num, int norma)
{
	t_listps	*node;

	node = malloc(sizeof(t_listps));
	if (!node)
		return (NULL);
	node->num = num;
	node->norma = norma;
	node->next = NULL;
	return (node);
}
