/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:56:16 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/09 15:02:54 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	l;
	size_t	i;

	l = 0;
	while (src[l])
	{
		l++;
	}
	if (n > 0)
	{
		i = 0;
		while (i < n - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, size);
	str[size] = '\0';
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	srcl;
	size_t	destl;
	size_t	in;

	srcl = ft_strlen(src);
	destl = 0;
	in = 0;
	if (!dst && n == 0 && src)
		return (srcl);
	while (dst[destl] && destl < n)
		destl++;
	if (destl == n)
		return (n + srcl);
	while (src[in] && (destl + in) < (n - 1))
	{
		dst[destl + in] = src[in];
		in++;
	}
	dst[destl + in] = '\0';
	return (destl + srcl);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(l1 + l2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, l1 + 1);
	ft_strlcat(str, s2, l1 + l2 + 1);
	return (str);
}
