/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:44:46 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/08/31 16:20:05 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pr_hexptr(unsigned long int nb, const char *base)
{
	int		i;
	int		len;
	char	str[16];

	i = 0;
	len = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (nb > 0)
	{
		str[i++] = base[nb % 16];
		nb = (nb / 16);
	}
	len += i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (ft_printf("0x0"));
	ft_putstr("0x");
	i = 2 + ft_pr_hexptr((unsigned long long)ptr, "0123456789abcdef");
	return (i);
}
/*	In OSX systems the return value should be "0x0".
	In Ubuntu return "(nil)"			*/
