/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:11:34 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:11:36 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	save = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new_list = ft_lstnew(tmp);
		if (!new_list)
		{
			del(tmp);
			ft_lstclear(&save, del);
			return (NULL);
		}
		ft_lstadd_back(&save, new_list);
		lst = lst->next;
	}
	return (save);
}
