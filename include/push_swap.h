/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:35:39 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/28 11:35:41 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Lib to delete before last push!!!
# include <stdio.h>
//

# include <unistd.h>
# include <stdlib.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int	num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack *num;
	int	args_n;
	int complete;
}	t_data;

t_stack	*ps_lstnew(int num);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstlast(t_stack *lst);
void	pusher(t_stack **stack, int to_sort);
void	err_handle(int type);
int		main(int argc, char **argv);
#endif
