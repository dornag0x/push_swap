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

void	init_b(t_stack *stack_b, int value)
{
	t_listps	*def;

	list_nurs(stack_b);
	if (!stack_b)
		return ;
	def = ps_lstnew(value);
	ps_lstadd_back(stack_b->data, def);
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

// function to delete before push:
void	print_test(t_stack *stack)
{
	t_listps	*tmp;
	t_listps	**oui;

	if (!stack)
		return ;
	oui = stack->data;
	tmp = *oui;
	//printf("len: %d\n", count_list(stack));
	printf("%d: %d\n", tmp->index, tmp->num);
	while (tmp->next)
	{
		tmp = tmp->next;
		printf("%d: %d\n", tmp->index, tmp->num);
	}
}

void	print_testlst(t_listps **lst)
{
	t_listps	*print;

	print = *lst;
	while(print)
	{
		printf("%d: %d\n", print->index, print->num);
		print = print->next;
	}
}

int count_list(t_stack *stack)
{
	t_listps *tmp;
	t_listps **cpy;
	int i;

	i = 0;
	cpy = malloc(sizeof(t_listps*));
	cpy = stack->data;
	tmp = *cpy;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
