/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:22:05 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/08/22 18:20:24 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_perrorputchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

static int	ft_perrorputstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(STDERR_FILENO, "(null)", 6));
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
		ft_perrorputchar(s[i++]);
	return (i);
}

static int	pr_perrorparam(char c, va_list *args)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 's')
		return (ft_perrorputstr(va_arg(*args, char *)));
	return (1);
}

/* Receives an error code and a formated string to be displayed on stderror 
	returns the error code */
int	ft_perror(int err_no, char const *str, ...)
{
	int		i;
	va_list	args;
	va_list	*pa;

	i = 0;
	va_start(args, str);
	pa = &args;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_perrorputchar(str[i]);
		else
		{
			i++;
			if (str[i] == '\0')
				return (err_no);
			else
				pr_perrorparam(str[i], pa);
		}
		i++;
	}
	va_end(args);
	return (err_no);
}
