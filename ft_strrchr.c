/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:49:32 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:32:40 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *string, int c)
{
	char	*res;
	int		i;

	res = (char *)string;
	i = 0;
	if (c > 255)
		c = c % 256;
	while (*(res + i) != '\0')
		i++;
	if (c == '\0')
		return (res + i);
	while (i >= 0)
	{
		if (c == *(res + i))
			return (res + i);
		i--;
	}
	return (NULL);
}
