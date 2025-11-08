/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:04:23 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/06/22 15:25:34 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Reads from the file descriptor and appends the result to the buffer.
static char	*read2buf(int fd, char *buf, int *p_file)
{
	int		bytes_read;
	char	*chunk;
	char	*new_buf;

	if (!buf)
		buf = ft_strcalloc(1, sizeof(char));
	if (!buf)
		return (NULL);
	chunk = ft_strcalloc((BUFFER_SIZE + 1), sizeof(char));
	if (!chunk)
		return (error_check(buf));
	bytes_read = read(fd, chunk, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		*p_file = 0;
		free(chunk);
		if (bytes_read == 0)
			return (buf);
		return (error_check(buf));
	}
	chunk[bytes_read] = '\0';
	new_buf = ft_strjoin(buf, chunk);
	free(chunk);
	free(buf);
	return (new_buf);
}

//Checks if there's a '\n' in the buffer. Returns 1 if so, 0 if not.
static int	find_line(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//Returns a string with the first line found in the buffer.
static char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		line = ft_strjoin("", buffer);
		if (!line)
			return (NULL);
		return (line);
	}
	line = ft_strcalloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\n')
		line[i] = buffer[i];
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//Creates a new buffer starting after the first '\n' character found and frees 
//the old one.
static char	*reset_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
		return (error_check(buffer));
	i++;
	while (buffer[i + j])
		j++;
	new_buffer = ft_strcalloc(j + 1, sizeof(char));
	if (!new_buffer)
		return (error_check(buffer));
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

//Returns the first line found in a file descriptor. 
//Each call returns the next line until the end of the file is reached.
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			file;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (buffer = error_check(buffer));
	file = 1;
	line = NULL;
	while (!find_line(buffer) && (file > 0))
		buffer = read2buf(fd, buffer, &file);
	if ((!buffer) || ((!buffer[0]) && (file <= 0)))
		return (buffer = error_check(buffer));
	if (file > 0)
	{
		line = extract_line(buffer);
		buffer = reset_buffer(buffer);
	}
	else if (file == 0)
	{
		line = ft_strjoin("", buffer);
		free (buffer);
		buffer = NULL;
	}
	return (line);
}
