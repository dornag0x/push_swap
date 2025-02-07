/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:42:53 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/03 15:40:18 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>
#include <color.h>

void	err_handle(t_err err)
{
	if (err == ERR_ALLOC)
	{
		ft_printf( RED "[ERROR]" NC " Wrong allocation!\n");
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_VALUE)
	{
		ft_printf( RED "[ERROR]" NC " Same value as been found!\n");
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_NULL)
	{
		ft_printf( RED "[ERROR]" NC " Value not found!\n");
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_ARG)
	{
		ft_printf( RED "[ERROR]" NC " You should provide more than 2 arguments!\n");
		exit(EXIT_FAILURE);
	}
}
