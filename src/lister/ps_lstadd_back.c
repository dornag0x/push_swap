/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:48 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 14:04:35 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_lstadd_back(t_listps **lst, t_listps *new)
{
	t_listps	*last;

	last = NULL;
	if (lst == NULL || new == NULL)
		return ;
	last = ps_lstlast(*lst);
	if (last != NULL)
		last->next = new;
	else
		*lst = new;
}
