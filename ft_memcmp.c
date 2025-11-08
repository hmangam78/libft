/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:26:25 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:24:01 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)buf1;
	s2 = (unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (count > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*s1 - *s2);
		count--;
	}
	return (*(s1 - 1) - *(s2 - 1));
}
