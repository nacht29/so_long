/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:36:53 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:22:07 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	c[10];
	char	c2[10];
	size_t	len = ft_strlcat(c, "132", 1);
	// size_t	len2 = strlcat(c2, "132", 1);
	// printf("len: %lu\nlen2: %lu\n", len, len2);
	printf("str: %s len: %lu\n", c, len);
	return (0);
}

*/
