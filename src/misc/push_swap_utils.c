/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:21:23 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/30 22:23:57 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int tab_len(char **tab)
{
	int	i;
	int res;

	i = 1;
	res = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

int	*super_atoi(char **numbers)
{
	int	*res;
	int	i;
	int j;

	i = 0;
	j = 1;
	res = malloc((sizeof(int*) * tab_len(numbers)));
	if (!res)
		err_handle(ERR_ALLOC);
	while (numbers[j])
	{
		res[i] = ft_atoi(numbers[j]);
		i++;
		j++;
	}
	// test:
	i = 0;
	while (res[i])
		i++;
	ft_printf("%d\n", i);
	// end test
	return (res);
}
