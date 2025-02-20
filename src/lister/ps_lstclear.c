/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:11:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 14:04:33 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_lstclear(t_listps **lst, void (*del)(void *))
{
	t_listps	*sack;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		sack = (*lst)->next;
		free(*lst);
		*lst = sack;
	}
	(*lst) = NULL;
}
