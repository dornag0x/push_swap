/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:35:39 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/30 22:30:24 by hfeufeu          ###   ########.fr       */
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

typedef struct s_listps
{
	int				num;
	struct s_listps	*next;
}	t_listps;

typedef struct s_stack
{
	t_listps	*num;
	int			name;
	int			args_n;
	int			complete;
}	t_stack;

int			*super_atoi(char **numbers);
t_listps	*ps_lstnew(int num);
void		ps_lstadd_back(t_listps **lst, t_listps *new);
t_listps	*ps_lstlast(t_listps *lst);
void		pusher(t_stack *stack_a, t_stack *stack_b, int *nums);
void		err_handle(int type);
int			main(int argc, char **argv);
#endif
