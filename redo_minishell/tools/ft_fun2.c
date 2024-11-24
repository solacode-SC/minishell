#include "minishell.h"

static int	cont_w1(const char *str)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_whitespace(str[i]))
		{
			count++;
			while (str[i] != '\0' && !is_whitespace(str[i]))
				i++;
		}
		else if (is_whitespace(str[i]))
			i++;
	}
	return (count);
}

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		i++;
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count != 0 && size > SIZE_MAX / count)
		return (0);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	memset(p, 0, count * size);
	return (p);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*cp;

	i = 0;
	if (str == NULL)
		return (NULL);
	cp = malloc(ft_strlen(str) + 1);
	if (cp == NULL)
		return (NULL);
	while (str[i])
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	**ft_split_it(char *str)
{
	char	**p;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	p = (char **)malloc((cont_w1(str) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		while (is_whitespace(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		j = 0;
		while (!is_whitespace(str[i]) && str[i] != '\0' && j++ >= 0)
			i++;
		p[n++] = ft_substr(str, i - j, j);
	}
	p[n] = NULL;
	return (p);
}

char	*ft_itoa(int nb)
{
	int		i;
	char	*p;
	long	b;

	b = nb;
	i = ft_len(b);
	p = malloc(i + 1);
	if (p == NULL)
		return (0);
	p[i] = '\0';
	if (b < 0)
	{
		p[0] = '-';
		b *= (-1);
	}
	if (b == 0)
		p[i - 1] = 48;
	while (b > 0)
	{
		p[i - 1] = (b % 10) + '0';
		i--;
		b /= 10;
	}
	return (p);
}

int	ft_isalnum(int c)
{
	if (c == '_')
		return (1);
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
