
#include "minishell.h"

char	*apend_char_str(char *str, char c)
{
	int		i;
	char	*new;

	i = ft_strlen(str);
	new = malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	if (str)
		free(str);
	return (new);
}


void	child_handler(int signum)
{
	(void)signum;
	exit(130);
}

void	child_handler1(int signum)
{
	(void)signum;
	exit(131);
}