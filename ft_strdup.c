/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:03:26 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:26:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *string)
{
	char	*cpy;
	int		i;

	cpy = malloc(ft_strlen(string) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		cpy[i] = string[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
