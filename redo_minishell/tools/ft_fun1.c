
#include "minishell.h"



int	count_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_strsrch(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	cont_w(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\t')
		{
			count++;
			while (str[i] != '\0' && str[i] != c && str[i] != '\t')
				i++;
		}
		else if (str[i] == c || str[i] == '\t')
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	p = (char **)malloc((cont_w(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] == c || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\t' && s[i] != '\0' && j++ >= 0)
			i++;
		p[n++] = ft_substr(s, i - j, j);
	}
	p[n] = NULL;
	return (p);
}