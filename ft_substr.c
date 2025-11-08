/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:30:47 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/04/30 12:44:19 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s + start) < len)
		len = (size_t)ft_strlen(s + start);
	res = ft_calloc(len + 1, 1);
	if (!res)
		return (NULL);
	while (len-- > 0)
		res[i++] = *(s + start++);
	return (res);
}
/*Retorna una substring que comienza en start y de len caracteres
 * Si start es mayor que la longitud de la cadena, devuelve ""
 * Si desde start hasta el final hay menos caracteres que len,
 * modifica len para reservar la memoria adecuada
 * Se reserva la memoria inicializando a cero y se copia el contenido de 
 * la string de origen desde start en adelante.
 */
