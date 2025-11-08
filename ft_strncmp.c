/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:02:11 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/24 23:28:38 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	while ((*string1 && *string2) && (count > 0))
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
		}
		else
			return ((unsigned char)*string1 - (unsigned char)*string2);
		count--;
	}
	if (count == 0)
		return (0);
	return ((unsigned char)*string1 - (unsigned char)*string2);
}
