/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:21:43 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/13 15:58:52 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long long int nb)
{
	int			i;
	int			len;
	long long	n;
	char		str[20];

	i = 0;
	n = nb;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		str[i++] = ((n % 10) + '0');
		n = (n / 10);
	}
	while (--i >= 0)
		len += ft_putchar(str[i]);
	return (len);
}
