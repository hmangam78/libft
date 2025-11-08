/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:21:43 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/13 15:58:27 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pr_hex(unsigned int nb, const char *base)
{
	int		i;
	int		len;
	char	str[12];

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
	while (i > 0)
		ft_putchar(str[--i]);
	return (len);
}
