#include "libft.h"

void	ft_memprint(void *ptr, size_t bytes, int data_size)
{
	unsigned char	*ucptr;
	size_t			i;

	if (data_size <= 0)
		return ;
	ucptr = ptr;
	while (bytes)
	{
		ft_printf("bytes:");
		i = data_size;
		bytes++;
		while (i-- && --bytes)
			ft_printf(" [%3d]", *ucptr++);
		ft_printf("\n");
	}
}
