#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	if (!dst && !src)
		return (0);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	return (dst);
}
