#include "opts.h"
#include "str.h"
#include <stddef.h>

t_opt	*ft_opts_getlong(t_opt opt_map[], char *name)
{
	int	i;

	i = 0;
	while (opt_map[i].c)
	{
		if (ft_strequ(opt_map[i].name, name))
			return (&opt_map[i]);
		i++;
	}
	return (NULL);
}
