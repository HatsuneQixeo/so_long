/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extract_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:38:28 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/29 00:38:28 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_lsttoaa(t_list *lst)
{
	char	**strlist;
	size_t	y;

	if (!lst)
		return (0);
	strlist = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!strlist)
		return (0);
	y = 0;
	while (lst)
	{
		strlist[y++] = ft_strtrim(lst->content, "\n");
		lst = lst->next;
	}
	strlist[y] = 0;
	return (strlist);
}

//Convert the file content in given file to 2d array(malloc)
//Note: This function trim away every '\n', while keeping empty lines
char	**ft_file_extract_lst(const char *file)
{
	int		fd;
	t_list	*lst;
	char	*str_part;
	char	**strlist;

	if (file)
		fd = ft_file_open(file);
	else
		fd = 0;
	lst = 0;
	str_part = get_next_line(fd);
	while (str_part)
	{
		ft_lstadd_back(&lst, ft_lstnew(str_part));
		str_part = get_next_line(fd);
	}
	close(fd);
	strlist = ft_lsttoaa(lst);
	ft_lstclear(&lst, free);
	return (strlist);
}
