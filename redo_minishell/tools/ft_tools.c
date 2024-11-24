#include "minishell.h"

int	ft_copy(char **cmd, char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		cmd[i] = ft_strdup(str[i]);
		i++;
	}
	return (i);
}



int	count_list(t_data *data)
{
	int	cont;

	cont = 0;
	while (data)
	{
		cont++;
		data = data->next;
	}
	return (cont);
}

char	**ft_addstring(char **str, t_lexer *lexer, t_env *envp)
{
	int		cont;
	t_var	var;

	var.j = 0;
	var.i = 0;
	if (str && !ft_strcmp(str[0], "export"))
		var.newstr = ft_expending_word(lexer->data, envp, 0);
	else
		var.newstr = ft_expending_word(lexer->data, envp, 1);
	cont = count_str(str) + count_str(var.newstr);
	var.cmd = ft_calloc(sizeof(char *), cont + 1);
	if (var.cmd == NULL)
		return (NULL);
	var.i = ft_copy(var.cmd, str);
	ft_copy(&var.cmd[var.i], var.newstr);
	ft_free1(str);
	ft_free1(var.newstr);
	return (var.cmd);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_printf(char *s1, char *s2, char *s3)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	return (1);
}

int	ft_printf1(char *s1, char s2, char *s3)
{
	ft_putstr(s1);
	write(2, &s2, 1);
	ft_putstr(s3);
	return (2);
}
