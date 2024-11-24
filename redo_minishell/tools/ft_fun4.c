#include "minishell.h"

int	ft_isalpha(int c)
{
	if (c == '_')
		return (1);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*skip_char(char *s, char c)
{
	int		n;
	char	*str;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	str = ft_calloc(sizeof(char), n + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s, n);
	return (str);
}

char	*ft_strjoinn(char *s1, char *ss2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 && !ss2)
		return (NULL);
	if (!s1)
	{
		result = ft_strdup(ss2);
		return (result);
	}
	if (!ss2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(ss2);
	result = ((char *)malloc(i + j + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, i);
	ft_memcpy(result + i, ss2, j);
	result[i + j] = '\0';
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (0);
	if (dest == src)
		return (dest);
	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}