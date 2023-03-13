/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extract_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:22:10 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/29 00:37:55 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Convert the file content in given file to 2d array(malloc)
//Note: This function exclude every '\n', including empty line
char	**ft_file_extract_split(const char *file)
{
	int		fd;
	char	*str;
	char	*str_part;
	char	**strlist;

	if (file)
		fd = ft_file_open(file);
	else
		fd = 0;
	str = 0;
	str_part = get_next_line(fd);
	while (str_part)
	{
		str = ft_strcombine(str, str_part);
		str_part = get_next_line(fd);
	}
	close(fd);
	strlist = ft_split(str, '\n');
	free(str);
	return (strlist);
}

// //Function similar to ft_split, but include c inside the individual str
// char	**ft_decompose(const char *str, char c)
// {
// 	char	**strlist;
// 	char	*find;
// 	size_t	y;

// 	if (!str)
// 		return (0);
// 	strlist = malloc(sizeof(char *) * (ft_chrcount(str, c) + 1));
// 	find = ft_strchr(str, c);
// 	while (find)
// 	{
// 		strlist[y++] = ft_substr(str, 0, ++find - str);
// 		str = find;
// 		find = ft_strchr(str, c);
// 	}
// 	strlist[y] = 0;
// 	return (strlist);
// }

// void	ft_strlistmodify_iter(char **strlist, const char *str,
// 			char *(ft_str)(const char *str1, const char *str2))
// {
// 	size_t	y;

// 	y = -1;
// 	if (!strlist || !ft_str)
// 		return ;
// 	while (strlist[++y])
// 		strlist[y] = ft_strmodify(strlist[y], str, ft_str);
// }

//Note: This function exclude every empty line at the start and end of the file
//while keeping the empty line in between
// char	**ft_file_extract_decompose(const char *file)
// {
// 	int		fd;
// 	char	*str;
// 	char	*str_part;
// 	char	**strlist;

// 	fd = ft_file_open(file);
// 	str = 0;
// 	str_part = get_next_line(fd);
// 	while (str_part)
// 	{
// 		str = ft_strcombine(str, str_part);
// 		str_part = get_next_line(fd);
// 	}
// 	close(fd);
// 	str = ft_strmodify(str, "\n", ft_strtrim);
// 	strlist = ft_decompose(str, '\n');
// 	ft_strlistmodify_iter(strlist, "\n", ft_strtrim);
// 	free(str);
// 	return (strlist);
// }
