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
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_VALUE)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_ARG)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_NOT_INT)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
