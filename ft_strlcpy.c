/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:42:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/23 10:56:53 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((i < (size - 1)) && (*src != '\0'))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	while (*src != '\0')
	{
		i++;
		src++;
	}
	return (i);
}
