/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:35:39 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/07 20:27:51 by hfeufeu          ###   ########.fr       */
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
	int			args_n;
	bool		check;
}	t_stack;

// To delete before push:
void		print_test(t_stack *stack);
int			count_list(t_stack *stack);

// Main:
void		pusher(t_stack *stack_a, t_stack *stack_b, int *nums);
int			main(int argc, char **argv);

// Algorithm:
int			valid_data(t_listps	*data);
char		*controller(t_stack *stack_a, t_stack *stack_b);
void		alg_2(t_stack *stack);
void		alg_3(t_stack *stack);

// Utils:
void		init_b(t_stack *stack_b, int value);
void		list_nurs(t_stack *stack);
int			*super_atoi(char **numbers);

// Action:
void		swapp(t_stack *stack);
void		pushh(t_stack *stack_1, t_stack *stack_2);
void		rotatee(t_stack *stack);
void		rev_rotatee(t_stack *stack);

// Lists:
void		ps_lstclear_last(t_listps	*lst);
void		ps_lstdelone(t_listps *lst, void (*del)(void*));
void		ps_lstadd_front(t_listps **lst, t_listps *new);
t_listps	*ps_lstnew(int num);
void		ps_lstadd_back(t_listps **lst, t_listps *new);
t_listps	*ps_lstlast(t_listps *lst);

// Errors handling:
void		err_handle(int type);
#endif
