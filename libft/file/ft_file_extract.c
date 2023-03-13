#include "libft.h"

char	*ft_file_extract(int fd)
{
	char	*str;
	char	*read;

	str = 0;
	read = get_next_line(fd);
	while (read)
	{
		str = ft_strcombine(str, read);
		read = get_next_line(fd);
	}
	return (str);
}