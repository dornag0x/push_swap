/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear2nd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:00:47 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/03 18:23:50 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ps_lstclear2nd(t_listps	*lst)
{
	t_listps	*tmp;
	t_listps	*prv;
	t_listps	*nxt;

	tmp = lst->next;
	prv = tmp;
	nxt = tmp->next;
	lst = lst->next;
	while (lst->next)
	{
		prv = nxt;
		lst = prv;
	}
	free(tmp);
}
