/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:35:39 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/03 18:02:17 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Lib to delete before last push!!!
# include <stdio.h>
//

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_listps
{
	int				num;
	struct s_listps	*next;
}	t_listps;

typedef struct s_stack
{
	t_listps	**data;
	int			name;
	int			args_n;
	bool		complete;
}	t_stack;

void		ps_lstclear2nd(t_listps	*lst);
void		list_nurs(t_stack *stack);
void		ps_lstdelone(t_listps *lst, void (*del)(void*));
void		swapp(t_stack *stack);
void		pushh(t_stack *stack_a, t_stack *stack_b);
void		ps_lstadd_front(t_listps **lst, t_listps *new);
void		controller(t_stack *stack_a, t_stack *stack_b);
int			*super_atoi(char **numbers);
t_listps	*ps_lstnew(int num);
void		ps_lstadd_back(t_listps **lst, t_listps *new);
t_listps	*ps_lstlast(t_listps *lst);
void		pusher(t_stack *stack_a, int *nums);
void		err_handle(int type);
int			main(int argc, char **argv);
// to delete before push:
void		print_test(t_stack *stack);
#endif
