/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:15:26 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:26:04 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *string, int c)
{
	char	*res;

	if (c > 255)
		c = (c % 256);
	res = (char *)string;
	while (*res != '\0')
	{
		if (*res == c)
			return (res);
		else
			res++;
	}
	if (c == '\0')
		return (res);
	return (NULL);
}
