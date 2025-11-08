/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:21:43 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/13 15:56:42 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pr_unsigned(unsigned int nb)
{
	int		i;
	int		len;
	char	str[12];

	i = 0;
	len = 0;
	while ((nb / 10) > 0)
	{
		str[i++] = ((nb % 10) + '0');
		nb = (nb / 10);
	}
	str[i] = ((nb % 10) + '0');
	len += i;
	while (i >= 0)
		ft_putchar(str[i--]);
	return (len + 1);
}
