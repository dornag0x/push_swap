/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:21:23 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 14:04:54 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	tab_len(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
		i++;
	return (i - 1);
}

void	free_stack(t_stack *stack)
{
	ps_lstclear(&stack->head, free);
	free(stack);
}

void	free_2darr(char **ptr)
{
	char	**tmp;

	if (!ptr)
		return ;
	tmp = ptr;
	while (ptr && *ptr)
		free(*ptr++);
	free(tmp);
}

static int	check_int(char *src, int j)
{
	int		i;
	long	num;

	i = 0;
	if ((!j && !src) || !src || check_if_valid(src))
		return (1);
	while (src[i])
	{
		if (!((src[i] >= '0' && src[i] <= '9') || (src[i] == '-')
				|| (src[i] == '+' && (src[i + 1] >= '0' && src[i + 1] <= '9'))))
			return (1);
		if (src[i] == '-' && (src[i - 1] >= '0' && src[i - 1] <= '9'))
			return (1);
		if (src[i] == '+' && (src[i - 1] >= '0' && src[i - 1] <= '9'))
			return (1);
		i++;
	}
	num = ft_atol(src);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

t_listps	*process_numbers(char **fill, t_listps *lst)
{
	int		j;
	long	tmp;

	j = 0;
	while (fill && fill[j])
	{
		if (check_int(fill[j], j) || !fill[0])
		{
			free_2darr(fill);
			ps_lstclear(&lst, free);
			return (NULL);
		}
		tmp = ft_atol(fill[j]);
		if (!lst)
			lst = ps_lstnew(tmp, 0);
		else
			ps_lstadd_back(&lst, ps_lstnew(tmp, 0));
		j++;
	}
	return (lst);
}
