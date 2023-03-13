#include "libft.h"

static int	ft_stroverlap(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	if (str1 < str2)
		while (*str1 && str1 != str2)
			str1++;
	else if (str1 > str2)
		while (*str2 && str2 != str1)
			str2++;
	return (str1 == str2);
}

//stroverlap
void	ft_printoverlap(const char *str1, const char *str2)
{
	ft_printf("str1: (%s)\n", str1);
	ft_printf("str2: (%s)\n", str2);
	ft_printf("stroverlap: %d\n\n", ft_stroverlap(str1, str2));
}

// int	main(void)
// {
// 	char	*miku;

// 	miku = "Hatsune Miku";
// 	ft_printoverlap(miku, ft_strstr(miku, "Miku"));
// 	ft_printoverlap(miku, "Miku");
// 	ft_printoverlap(miku, ft_strstr(miku, ""));
// 	ft_printoverlap(miku, "Hatsune Miku");
// 	ft_printoverlap(miku, ft_strchr(miku, 0));
// 	ft_printoverlap(miku, "");
// 	ft_printf("/////REVERSED/////\n");
// 	ft_printoverlap(ft_strstr(miku, "Miku"), miku);
// 	ft_printoverlap("Miku", miku);
// 	ft_printoverlap(ft_strstr(miku, ""), miku);
// 	ft_printoverlap("Hatsune Miku", miku);
// 	ft_printoverlap(ft_strchr(miku, 0), miku);
// 	ft_printoverlap("", miku);
// }

char	*ft_strinsert(const char *first, const char *insert, const char *last)
{
	char	*str;
	size_t	len;

	if (!first || !insert || !last)
		return (0);
	else if ((first + ft_strlen(first) - ft_strlen(last)) != last)
		return (ft_strmodify(ft_strjoin(first, insert), last, ft_strjoin));
	else if (first >= last)
		return (0);
	len = ft_strlen(first) + ft_strlen(insert) + 1;
	str = malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, first, last - first + 1);
	ft_strlcat(str, insert, len);
	ft_strlcat(str, last, len);
	return (str);
}

// Insert
static void	ft_printinsert(char *first, char *insert, char *last)
{
	char	*str;

	str = ft_strinsert(first, insert, last);
	ft_printf("first:	(%s)\n", first, insert, last);
	ft_printf("insert:	(%s)\n", insert);
	ft_printf("last:	(%s)\n", last);
	if (ft_stroverlap(first, last))
		ft_printf("Overlap: %s\n", "yes");
	else
	{
		ft_printf("Overlap: %s", "no");
		ft_printf(", len first copy: %d\n", last - first);
	}
	ft_printf("str:	(%s)\n\n", str);
	free(str);
}

// int	main(void)
// {
// 	char	*miku;

// 	miku = "HatsuneMiku";
// 	ft_printinsert(miku, " ", ft_strstr(miku, "Miku"));
// 	ft_printinsert(ft_strstr(miku, "Miku"), " ", miku);
// 	ft_printinsert("Miku", " ", miku);
// 	ft_printinsert(miku, " ", "Miku");
// 	ft_printinsert("Hatsune", " ", "Miku");
// 	printf("%u\n", (unsigned long)-1);
// 	ft_printf("%u\n", (unsigned long)-1);
// 	printf("%x\n", (unsigned long)-1);
// 	ft_printf("%x\n", (unsigned long)-1);
// 	printf("%p\n", (unsigned long)-1);
// 	printf("%lp\n", (unsigned long)-1);
// 	ft_printf("%p\n", (unsigned long)-1);
// }

//This function takes in an allocated string
// and keep adding the rest of the string to the back
char	*ft_strmerge(char *str, ...)
{
	va_list	args;
	char	*str_part;

	va_start(args, str);
	str_part = va_arg(args, char *);
	while (str_part)
	{
		str = ft_strmodify(str, str_part, ft_strjoin);
		str_part = va_arg(args, char *);
	}
	va_end(args);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strmerge(ft_strdup("Hatsune"), " ", "Miku", " ", "is", " ", "love", "\n", "Hatsune", " ", "Miku", " ", "is", " ", "live");
// 	ft_printf("strmerge: %s\n", str);
// 	free(str);
// }
