

#include "minishell.h"


int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	set_to_env(char *env, t_env **envp)
{
	t_env	*new;
	char	*str;
	char	*var;

	var = skip_char(env, '+');
	new = *envp;
	while (new)
	{
		if (!ft_strcmp(var, new->var))
		{
			str = ft_strsrch(env, '=');
			if (ft_strsrch(new->value, '='))
				str = ft_strjoinn(new->value, &str[1]);
			else
				str = ft_strjoinn(new->value, &str[0]);
			free(new->value);
			new->value = str;
			free(var);
			return (1);
		}
		new = new->next;
	}
	ft_setenv(env, envp);
	free(var);
	return (1);
}

int	ft_export(t_data *data, t_env **env)
{
	int		i;
	char	*str;
	int		exit_s;

	i = 1;
	exit_s = 0;
	if (data->cmd[1] == NULL)
		sort_print(*env);
	while (data->cmd[i])
	{
		str = ft_strsrch(data->cmd[i], '+');
		if (!ft_isalpha(data->cmd[i][0]) && data->cmd[i][0] != '_')
			exit_s = ft_printf("minishell: export:`", data->cmd[i],
					"': not a valid identifier\n");
		else if (str && str[1] == '=')
			set_to_env(data->cmd[i], env);
		else if (ft_check_str(data->cmd[i]) == 0)
			exit_s = ft_printf("minishell: export:`", data->cmd[i],
					"': not a valid identifier\n");
		else
			ft_setenv(data->cmd[i], env);
		i++;
	}
	return (exit_s);
}
