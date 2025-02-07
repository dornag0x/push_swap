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

void	check_arg(int *arg)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		j = (i + 1);
		while (arg[j])
		{
			if (arg[i] == arg[j])
				err_handle(ERR_VALUE);
			j++;
		}
		i++;
	}
}
