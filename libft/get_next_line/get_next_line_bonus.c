/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:35:37 by chonorat          #+#    #+#             */
/*   Updated: 2023/08/30 12:31:40 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*prepare_for_next(char *stash)
{
	char	*prepared;
	int		index;
	int		index_j;

	if (!stash)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\0')
		return (free(stash), stash = NULL, NULL);
	prepared = ft_calloc_gnl((ft_strlen_gnl(&stash[index++])), sizeof(char));
	if (!prepared)
		return (free(stash), stash = NULL, NULL);
	index_j = 0;
	while (stash[index])
		prepared[index_j++] = stash[index++];
	prepared[index_j] = '\0';
	return (free(stash), stash = NULL, prepared);
}

char	*stash_to_line(char *stash)
{
	char	*stash_line;
	int		index;

	if (stash[0] == '\0')
		return (NULL);
	index = 0;
	while (stash[index] != '\n' && stash[index])
		index++;
	stash_line = ft_calloc_gnl(index + 1 + ft_strchr_gnl(stash, '\n'),
			sizeof(char));
	if (!stash_line)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
	{
		stash_line[index] = stash[index];
		index++;
	}
	if (stash[index] == '\n')
	{
		stash_line[index] = stash[index];
		index++;
	}
	return (stash_line[index] = '\0', stash_line);
}

char	*add_to_stash(char *buffer, char *stash)
{
	char	*join;

	join = ft_strjoin_gnl(stash, buffer);
	free(stash);
	return (join);
}

char	*read_fd(int fd, char *stash, int read_switch)
{
	char	buffer[BUFFER_SIZE + 1];

	if (!stash)
	{
		stash = ft_calloc_gnl(1, 1);
		if (!stash)
			return (NULL);
	}
	while (read_switch > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		read_switch = read(fd, buffer, BUFFER_SIZE);
		if (read_switch == -1)
		{
			if (stash)
				return (free(stash), stash = NULL, NULL);
			return (NULL);
		}
		buffer[read_switch] = '\0';
		stash = add_to_stash(buffer, stash);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[10240];
	char		*line;
	int			read_switch;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash[fd])
		{
			free(stash[fd]);
			stash[fd] = NULL;
		}
		return (NULL);
	}
	read_switch = 1;
	stash[fd] = read_fd(fd, stash[fd], read_switch);
	if (!stash[fd])
		return (NULL);
	line = stash_to_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = prepare_for_next(stash[fd]);
	return (line);
}
