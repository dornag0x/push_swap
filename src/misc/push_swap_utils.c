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

void	list_nurs(t_stack *stack)
{
	t_listps **tmp;

	tmp = malloc(sizeof(t_listps*));
	if (!tmp)
		return ;
	stack->data = tmp;
}

int tab_len(char **tab)
{
	int	i;
	int res;

	i = 1;
	res = 0;
	while (tab[i])
	{
		res += ft_strlen(tab[i]);
		i++;
	}
	return (res);
}

int	*super_atoi(char **numbers)
{
	int	*res;
	int	i;
	int j;

	i = 0;
	j = 1;
	res = malloc(sizeof(int) * tab_len(numbers));
	if (!res)
		return (0);
	while (numbers[j])
	{
		res[i] = ft_atoi(numbers[j]);
		i++;
		j++;
	}
	return (res);
}
