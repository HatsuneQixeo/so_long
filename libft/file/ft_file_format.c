/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:22:16 by hqixeo            #+#    #+#             */
/*   Updated: 2022/09/27 23:22:18 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Return 1 if filename end with given format
//Return 0 if filename does not end with given format
//and prints out an error message 
int	ft_file_format(const char *file, const char *format)
{
	ft_printf("file - formatlen: %s\n", file - ft_strlen(format));
	if (ft_strcmp(file + (ft_strlen(file) - ft_strlen(format)), format))
		return (!ft_dprintf(2, "(%s) is not (%s) file\n", file, format));
	return (1);
}
