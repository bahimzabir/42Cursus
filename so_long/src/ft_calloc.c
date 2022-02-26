#include "../include/solong.h"

void	*ft_calloc(size_t i, size_t s)
{
	char	*p;
	size_t	j;

	p = (char *)malloc(i * s);
	if (!p)
		return (NULL);
	j = 0;
	while (j < i * s)
	{
		p[j] = 0;
		j++;
	}
	return (p);
}