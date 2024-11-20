#include "../minishell.h"

char	**ft_catstr(char **str, char **str1)
{
	t_var	var;

	var.i = 0;
	var.j = -1;
	var.n = count_str(str) + count_str(str1);
	var.newstr = ft_calloc(sizeof(char *), var.n + 1);
	if (!var.newstr)
		return (NULL);
	while (str && str[var.i])
		var.newstr[++var.j] = ft_strdup(str[var.i++]);
	if (var.j == -1)
		var.j = 0;
	var.var = ft_strjoinn(var.newstr[var.j], str1[0]);
	if (var.newstr[var.j])
		free(var.newstr[var.j]);
	var.newstr[var.j] = var.var;
	var.j++;
	var.i = 1;
	while (str1 && str1[0] && str1[var.i])
		var.newstr[var.j++] = ft_strdup(str1[var.i++]);
	ft_free1(str);
	ft_free1(str1);
	return (var.newstr);
}
