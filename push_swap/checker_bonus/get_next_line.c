/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:58:30 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:24:17 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*fill_buff(int fd, char *buff);
static char	*extract_line(char *buffer);
static char	*rst_buff(char *oldbuff, int linelength);
static char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free_and_null(&buff));
	if (!ft_strchr(buff, '\n'))
		buff = fill_buff(fd, buff);
	if (!buff || !*buff)
		return (free_and_null(&buff));
	line = extract_line(buff);
	if (!line)
		return (free_and_null(&buff));
	buff = rst_buff(buff, ft_strlen(line));
	return (line);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinstr;
	int		size1;
	int		size2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	joinstr = malloc((size1 + size2 + 1) * sizeof(char));
	if (joinstr == NULL)
		return (NULL);
	ft_strlcpy(joinstr, s1, size1 + 1);
	ft_strlcpy(joinstr + size1, s2, size2 + 1);
	free(s1);
	return (joinstr);
}

static char	*fill_buff(int fd, char *buff)
{
	char	*temp_buff;
	int		byteread;

	temp_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buff)
		return (free_and_null(&buff));
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, temp_buff, BUFFER_SIZE);
		if (byteread < 0)
		{
			free(temp_buff);
			free(buff);
			return (NULL);
		}
		temp_buff[byteread] = '\0';
		buff = ft_strjoin(buff, temp_buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(temp_buff);
	if (!buff)
		return (free_and_null(&buff));
	return (buff);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	return (line);
}

static char	*rst_buff(char *oldbuff, int linelength)
{
	char	*newbuff;
	int		bufflen;

	bufflen = ft_strlen(oldbuff);
	if (linelength > bufflen)
		return (free_and_null(&oldbuff));
	newbuff = malloc((bufflen - linelength + 1) * sizeof(char));
	if (!newbuff)
		return (NULL);
	ft_strlcpy(newbuff, oldbuff + linelength, bufflen - linelength + 1);
	free(oldbuff);
	return (newbuff);
}
