/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 08:41:15 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/05 09:08:13 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	get_len(long num)
{
	int	i;

	i = 0;
	while ((num / 10) > 0)
	{
		num = num / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len = 1;
		num *= -1;
	}
	len += get_len(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = 45;
	return (str);
}
