/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:42:53 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/12/29 13:42:54 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	err_handle(t_err err)
{
	if (err == ERR_ALLOC)
	{
		ft_printf("Wrong allocation!");
		exit(EXIT_FAILURE);
	}
}
