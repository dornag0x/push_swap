/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:42:23 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/10/11 08:55:43 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char c, const char *set)
{
	while (*set && c != *set)
		set++;
	if (c == *set)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start_str;
	const char	*end_str;
	char		*trim;

	if (!s1 || !set)
		return (NULL);
	start_str = s1;
	while (*start_str && find_set(*start_str, set))
		start_str++;
	end_str = s1 + ft_strlen(s1);
	while (end_str > start_str && find_set(*(end_str - 1), set))
		end_str--;
	trim = malloc(sizeof(char) * (end_str - start_str + 1));
	if (!trim)
		return (NULL);
	ft_memcpy(trim, start_str, end_str - start_str);
	*(trim + (end_str - start_str)) = 0;
	return (trim);
}
