/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:24:32 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/01 00:41:43 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if ((!s && !d) && count > 0)
		return (NULL);
	if (d < s)
	{
		i = 0;
		while (i < count)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (count-- > 0)
			d[count] = s[count];
	}
	return (dest);
}
