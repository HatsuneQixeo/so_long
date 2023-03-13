#include "libft.h"
#include <string.h>
void	ft_memprint(void *ptr, size_t bytes, int bytes_per_len);

static void	memset_sucks(unsigned int nbr, void *(set)(void *, int, size_t))
{
	unsigned int	*ptr;
	size_t			len;

	len = sizeof(int) * 10;
	ptr = malloc(len);
	ft_printf("nbr: %u\n", nbr);
	if (set == ft_memset)
		ft_printf("ft");
	set(ptr, len, sizeof(int));
	ft_memprint(ptr, len, sizeof(int));
	ft_printf("%u\n", *ptr);
}

int	main(void)
{
	memset_sucks(0x000ff + (256 * 256 * 256) * 100, memset);
	memset_sucks(0x000ff + (256 * 256 * 256) * 100, ft_memset);
}
