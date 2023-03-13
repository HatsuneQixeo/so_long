/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:22:22 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/27 23:22:24 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Open the file from given path as read_only
//and prints out an error message if the fd is invalid
//Return the fd regardless of valid or invalid
int	ft_file_open(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Invalid file: %s\n", file);
	return (fd);
}
