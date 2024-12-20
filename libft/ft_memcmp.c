/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MPazouki <mpazouki@42student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 09:13:35 by MPazouki          #+#    #+#             */
/*   Updated: 2024-06-21 09:13:35 by MPazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;

	if (n == 0)
		return (0);
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char data1[] = "Hello, World!";
	char data2[] = "Hello, World!";
	char data3[] = "Hello, world!";  // Note the lowercase 'w'

	// Compare data1 and data2
	if (ft_memcmp(data1, data2, strlen(data1)) == 0) {
		printf("data1 and data2 are equal\n");
	} else {
		printf("data1 and data2 are not equal\n");
	}

	// Compare data1 and data3
	if (ft_memcmp(data1, data3, strlen(data1)) == 0) {
		printf("data1 and data3 are equal\n");
	} else {
		printf("data1 and data3 are not equal\n");
	}

	return 0;
}
*/

/*
DESCRIPTION
	   The memcmp() function compares the first n bytes
	    (each interpreted as unsigned char) of the memory areas s1 and s2.

RETURN VALUE
	   The memcmp() function returns an integer less than,
	    equal to, or greater than zero if the first n bytes of s1 is found,
		 respectively, to be less than, to match, or be greater than 
		 the first n bytes of s2.

	   For a nonzero return value, the sign is determined 
	   by the sign of the difference between the first pair of bytes 
	   (interpreted as unsigned char) that differ in s1 and s2.

	   If n is zero, the return value is zero.
*/