/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:35:39 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/15 12:23:48 by hfeufeu          ###   ########.fr       */
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
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

typedef enum ERR
{
	ERR_ALLOC,
	ERR_VALUE,
	ERR_NULL,
	ERR_ARG,
	ERR_NOT_INT
}	t_err;

typedef struct s_listps
{
	int				num;
	int				index;
	int				norma;
	struct s_listps	*next;
}	t_listps;

typedef struct s_stack
{
	t_listps	*head;
	t_listps	*tails;
	int			size;
}	t_stack;

// To delete before push:
void		printstack(t_listps *stack);
void		printnorma(t_listps *stack);

// Main:
void		pusher(t_stack *stack_a, t_stack *stack_b, char **nums);
t_listps	*lister(char **argv);
int			main(int argc, char **argv);

// Algorithm:
int			valid_data(t_listps	*data);
void		controller(t_stack *stack_a, t_stack *stack_b);
void		radix_sort(t_stack *stack_a, t_stack *stack_b);
void		normalizer(t_listps *stack, int size);
void		alg_2(t_stack *stack);
void		alg_3(t_stack *stack);
void		alg_4(t_stack *stack_a, t_stack *stack_b);
void		alg_5(t_stack *stack_a, t_stack *stack_b);

// Utils:
void		init_b(t_stack *stack_b, int value, int index);
void		list_nurs(t_stack *stack);
int			*super_atoi(char **numbers);
t_listps	*int_sort(t_listps *stack);
void		free_stack(t_stack *stack);

// Action:
void		swapp(t_stack *stack, int s);
void		pushh(t_stack *stack_1, t_stack *stack_2, int s);
void		rotatee(t_stack *stack, int s);
void		rev_rotatee(t_stack *stack, int s);

// Lists:
void		ps_lstclear_last(t_listps	*lst);
void		ps_lstdelone(t_listps *lst, void (*del)(void*));
void		ps_lstadd_front(t_listps **lst, t_listps *new);
t_listps	*ps_lstnew(int num, int norma);
void		ps_lstadd_back(t_listps **lst, t_listps *new);
t_listps	*ps_lstlast(t_listps *lst);
t_listps	*ps_lstcpy(t_listps *original);
void		ps_lstclear(t_listps **lst, void (*del)(void*));
int			ps_lstsize(t_listps *lst);

// Errors handling:
void		check_arg(t_listps *arg);
void		err_handle(t_err err);
#endif
