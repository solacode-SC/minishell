
#include "minishell.h"

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
