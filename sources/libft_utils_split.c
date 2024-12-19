/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:09:50 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:33:55 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void	*src, size_t	numBytes)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	while (numBytes--)
	{
		*(char *) dest++ = *(char *) src++;
	}
	return (dest_ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dups;

	len = ft_strlen(s) + 1;
	dups = malloc(len);
	if (dups == NULL)
		return (NULL);
	ft_memcpy (dups, s, len);
	return (dups);
}

static char	*allocate_and_copy_substr(const char *s, size_t start,
									size_t alloc_size)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!substr)
		return (NULL);
	while (i < alloc_size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	alloc_size;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s - start < len)
		alloc_size = len_s - start;
	else
		alloc_size = len;
	return (allocate_and_copy_substr(s, start, alloc_size));
}
