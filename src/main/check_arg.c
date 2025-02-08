/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:27:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/03 15:41:31 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

void	check_arg(t_listps *arg)
{
	t_listps	*tmp;
	t_listps	*next;

	tmp = arg;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (next->num == tmp->num)
				err_handle(ERR_VALUE);
			next = next->next;
		}
		tmp = tmp->next;
	}
}
