/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@42student.42malaga.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 08:41:15 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/04 12:53:54 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itobin(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = 0;
	str = malloc(sizeof(char) * 9);
	if (!str)
		return (NULL);
	while (i < 9)
		str[i++] = '\0';
	i = 7;
	while (i >= 0)
	{
		str[i--] = (num % 2) + '0';
		num = num / 2;
	}
	return (str);
}
