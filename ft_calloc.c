/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:12:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:23:20 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*pt;

	pt = malloc(num * size);
	if (!pt)
		return (NULL);
	else
	{
		ft_bzero(pt, (num * size));
	}
	return (pt);
}
