/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@42student.42malaga.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:03:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/26 19:37:18 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putchar('(');
		ft_putchar('n');
		ft_putchar('u');
		ft_putchar('l');
		ft_putchar('l');
		ft_putchar(')');
		return (6);
	}
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}
