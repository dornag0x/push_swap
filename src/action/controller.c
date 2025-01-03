/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:10:04 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 16:10:06 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	controller(t_stack *s_a, t_stack *s_b)
{
	t_listps	*pivot;
	t_listps	*tmp;
	t_listps	*tmp1;
	int			i;
	bool		ver;

	i = 0;
	ver = false;
	swapp(s_a);
	tmp = *s_a->data;
	printf("b: %d\n", tmp->num);
	/*while (tmp->next)
	{
		printf("b: %d\n", tmp->num);
		tmp = tmp->next;
	}*/
}
