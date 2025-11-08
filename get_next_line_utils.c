/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:06:21 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/22 15:27:02 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Frees buffer and returns NULL.
char	*error_check(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (NULL);
}
