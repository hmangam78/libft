/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/30 11:51:11 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = (size_t)ft_strlen(dst);
	if (size <= k)
	{
		if ((ft_strlen(src) + size) < (size_t)ft_strlen(src))
			return (ft_strlen(src));
		else
			return (ft_strlen(src) + size);
	}
	while (*(dst + i) != '\0')
		i++;
	while ((i < size - 1) && (*(src + j) != '\0'))
		*(dst + i++) = *(src + j++);
	*(dst + i) = '\0';
	return (ft_strlen(src) + k);
}

