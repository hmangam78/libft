/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:23:11 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/22 15:24:14 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcalloc(size_t num, size_t size)
{
	char	*pt;
	size_t	i;

	i = 0;
	if (num <= 0)
		return (NULL);
	pt = malloc(num * size);
	if (!pt)
		return (NULL);
	else
	{
		while (i < size)
		{
			pt[i] = '\0';
			i++;
		}
	}
	return (pt);
}
