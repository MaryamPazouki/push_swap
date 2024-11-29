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

//----------------------------------SPLIT-----------------------------------------------------

static size_t	count_word(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
		{
			i++;
		}
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t			words;
	char			**array;

	words = count_word(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}