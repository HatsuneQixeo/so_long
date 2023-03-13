#include "libft.h"

char	*ft_strchr_set(const char *str, const char *set)
{
	if (!*set)
		return ((char *)str);
	while (*str)
		if (ft_strchr(set, *str++))
			return ((char *)--str);
	return (0);
}
