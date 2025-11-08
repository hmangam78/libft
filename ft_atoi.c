/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:20:12 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/08/30 17:10:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int	num;
	int	signo;

	num = 0;
	signo = 1;
	while ((((*string >= 9) && (*string <= 13)) || (*string == ' ')) && *string)
		string++;
	if ((*string == '-') || (*string == '+'))
	{
		if (*string == '-')
			signo = -signo;
		string++;
	}
	while ((*string >= '0') && (*string <= '9'))
	{
		num = (10 * num) + (*string - '0');
		string++;
	}
	num = signo * num;
	return (num);
}
