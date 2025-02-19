/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:42:53 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/19 16:52:36 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <push_swap.h>

void	err_handle(t_err err)
{
	if (err == ERR_ALLOC)
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
