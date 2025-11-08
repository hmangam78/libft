/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 08:20:03 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/05/05 09:10:48 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	n_word;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		n_word = 0;
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			if (n_word == 0)
			{
				words++;
				n_word = 1;
			}
			i++;
		}
	}
	return (words);
}

static int	extract_word(char *buffer, char const *s, int index, char c)
{
	int	j;

	j = 0;
	while ((s[index] != c) && (s[index] != '\0'))
		buffer[j++] = s[index++];
	buffer[j] = '\0';
	return (j);
}

static char	**kill(char **strs, int index)
{
	while (index >= 0)
		free(strs[index--]);
	free(strs);
	return (NULL);
}

static int	skip_c(char const *s, char c)
{
	int	count;

	count = 0;
	while ((*s == c) && (*s))
	{
		s++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	buffer[400];
	int		len;
	int		k;

	len = 0;
	k = 0;
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		s += skip_c(s, c);
		if (*s != '\0')
		{
			len = extract_word(buffer, s, 0, c);
			strs[k] = malloc(sizeof(char) * (len + 1));
			if (!strs[k])
				return (kill(strs, k));
			ft_strlcpy(strs[k++], buffer, len + 1);
			s += len;
		}
	}
	strs[k] = NULL;
	return (strs);
}
