/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:00:47 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/03 18:23:02 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ps_lstclear_last(t_listps *lst)
{
	t_listps	*prev;

	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	prev->next = NULL;
	free(lst);
}
