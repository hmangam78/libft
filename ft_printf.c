/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:14:36 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/08/31 16:19:32 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pr_param(char c, va_list *args)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'p')
		return (ft_putptr(va_arg((*args), uintptr_t)));
	else if ((c == 'd') || (c == 'i'))
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_pr_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_pr_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_pr_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	return (1);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		length;
	va_list	args;
	va_list	*pa;

	i = 0;
	length = 0;
	va_start(args, str);
	pa = &args;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			length += ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] == '\0')
				return (0);
			else
				length += pr_param(str[i], pa);
		}
		i++;
	}
	return (length);
	va_end(args);
}
