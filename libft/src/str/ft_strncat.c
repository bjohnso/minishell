#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *first;

	first = s1;
	while (*s1)
		s1++;
	while (*s2 && n > 0)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (first);
}
