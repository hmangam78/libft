/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:34:45 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/25 18:02:25 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		l1;
	int		l2;
	int		i;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	len = (l1 + l2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i])
		res[l1++] = s2[i];
	res[l1] = '\0';
	return (res);
}
