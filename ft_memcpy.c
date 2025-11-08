/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:41:33 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/30 11:26:47 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	if (!dest_str && !src_str)
		return (0);
	tempdst = (unsigned char *)dest_str;
	tempsrc = (unsigned char *)src_str;
	while (n > 0)
	{
		*(tempdst++) = *(tempsrc++);
		n--;
	}
	return (dest_str);
}
