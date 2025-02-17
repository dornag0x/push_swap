/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:21:23 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/17 21:23:21 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	free_stack(t_stack *stack)
{
	ps_lstclear(&stack->head, free);
	free(stack);
}

static void	free_2darr(char **ptr)
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
	int i;

	i = 0;
	if ((!j && !src) || check_if_valid(src))
		err_handle(ERR_ARG);
	while (src[i])
	{
		if (!((src[i] >= '0' && src[i] <= '9') || (src[i] == '-') || 
				(src[i] == '+' && (src[i + 1] >= '0' && src[i + 1] <= '9'))))
			return (1);
		if (src[i] == '-' && (src[i - 1] >= '0' && src[i - 1] <= '9'))
			return (1);
		if (src[i] == '+' && (src[i - 1] >= '0' && src[i - 1] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	printnorma(t_listps *stack)
{
	while (stack)
	{
		printf("%d\n", stack->norma);
		stack = stack->next;
	}
}

t_listps	*lister(char **argv)
{
	int			i;
	int			j;
	int			tmp;
	t_listps	*lst;
	char		**fill;

	i = 0;
	lst = NULL;
	while (argv[++i])
	{
		fill = ft_split(argv[i], ' ');
		if (!fill || !fill[0])
		{
			free_2darr(fill);
			ps_lstclear(&lst, free);
			return (NULL);
		}
		j = 0;
		while (fill && fill[j])
		{
			if (check_int(fill[j], j) || !fill[0])
			{
				free_2darr(fill);
				ps_lstclear(&lst, free);
				return (NULL);
			}
			tmp = ft_atoi(fill[j]);
			if (!lst)
				lst = ps_lstnew(tmp, 0);
			else
				ps_lstadd_back(&lst, ps_lstnew(tmp, 0));
			j++;
		}
		free_2darr(fill);
	}
	return (lst);
}
