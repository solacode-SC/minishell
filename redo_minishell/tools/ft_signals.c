
#include "minishell.h"

extern t_var_free	g_var_f;

void	f(int sig)
{
	(void)sig;
	free_data(g_var_f.data);
	free_envp(g_var_f.env);
	clear_history();
	exit(130);
}

void	handle_signal1(int sig)
{
	(void)sig;
	printf("\n");
	g_var_f.exit_s = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}