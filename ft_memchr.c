/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:40:29 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:24:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*s;

	s = (unsigned char *)buf;
	c = (unsigned char)c;
	if (c > 255)
		c = (c % 256);
	while (count > 0)
	{
		if (c == *s)
			return ((void *)s);
		count--;
		s++;
	}
	return (NULL);
}
