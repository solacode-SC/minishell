
#include "minishell.h"

static int	ft_var(char *str, int i, int res, int sign)
{
	if (str[i] != '\0')
	{
		ft_printf("bash: exit: ", str, ":numeric argument required\n");
		return (2);
	}
	return ((res * sign));
}

static int	check_long(int sign, long long res, char *str, int i)
{
	if (sign == 1 && res > (LLONG_MAX - (str[i] - '0')) / 10)
	{
		ft_printf("minshell: exit: ", str, ": numeric argument required\n");
		return (1);
	}
	else if (sign == -1 && (-res) < (LLONG_MIN + (str[i] - '0')) / 10)
	{
		ft_printf("minshell: exit:", str, ": numeric argument required\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long long	res;
	int			sign;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (check_long(sign, res, str, i))
			return (2);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (ft_var(str, i, res, sign));
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	int		j;

	i = start;
	j = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		ptr[j] = s[i];
		i++;
		j++;
		len--;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	lens;

	j = 0;
	lens = 0;
	if (!s)
		return (NULL);
	while (s[lens])
		lens++;
	if (len > lens - start)
		len = lens - start;
	if (lens <= start)
	{
		ptr = malloc(1 * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[j] = '\0';
		return (ptr);
	}
	ptr = ft_sub(s, start, len);
	return (ptr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
