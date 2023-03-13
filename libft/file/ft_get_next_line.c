/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:41:10 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/26 19:41:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_line(int fd, char *str_saved)
{
	char	*str_part;
	int		len_read;

	len_read = BUFFER_SIZE;
	str_part = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(str_saved, '\n') && len_read == BUFFER_SIZE)
	{
		len_read = read(fd, str_part, BUFFER_SIZE);
		if (len_read == -1)
		{
			ft_dprintf(2, "get_next_line error: read returned -1\n");
			break ;
		}
		str_part[len_read] = 0;
		str_saved = ft_strmodify(str_saved, str_part, ft_strjoin);
	}
	free(str_part);
	return (str_saved);
}

static char	*separator(char **str_saved)
{
	char	*str_main;
	char	*str_nl;
	char	*str_tmp;

	str_nl = ft_strchr(*str_saved, '\n');
	if (str_nl)
	{
		str_main = ft_substr(*str_saved, 0, ++str_nl - *str_saved);
		str_tmp = ft_strdup(str_nl);
		free(*str_saved);
	}
	else if (**str_saved)
	{
		str_main = *str_saved;
		str_tmp = 0;
	}
	else
	{
		str_main = 0;
		str_tmp = 0;
		free(*str_saved);
	}
	*str_saved = str_tmp;
	return (str_main);
}

char	*get_next_line(int fd)
{
	static char	*str_saved[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (0);
	if (!str_saved[fd])
		str_saved[fd] = ft_strdup("");
	str_saved[fd] = read_line(fd, str_saved[fd]);
	return (separator(&str_saved[fd]));
}
