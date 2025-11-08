/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:49:48 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/05 09:13:54 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_c(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*n_str(char const *s1, int i, int j)
{
	char	*str;

	if (i > j)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = ft_calloc((j - i + 2), 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, (j - i + 2));
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = (ft_strlen(s1) - 1);
	while (find_c(*(s1 + start), set) == 1 && (*(s1 + start) != '\0'))
		start++;
	while (find_c(*(s1 + end), set) == 1 && (end > 0))
	{
		end--;
	}
	return (n_str(s1, start, end));
}
