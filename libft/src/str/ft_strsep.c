#include "str.h"
#include <stddef.h>

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*begin;
	char	*end;

	if (!(begin = *stringp))
		return (NULL);
	if (!delim[0] || !delim[1])
	{
		if (!delim[0])
			end = NULL;
		else if (*begin == delim[0])
			end = begin;
		end = (!*begin) ? NULL : ft_strchr(begin + 1, delim[0]);
	}
	else
		end = ft_strpbrk(begin, delim);
	if (end)
	{
		*end = '\0';
		*stringp = ++end;
	}
	else
		*stringp = NULL;
	return (begin);
}
