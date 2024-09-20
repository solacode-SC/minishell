
#include "minishell.h"


int main(int ac, char **av, char **envp) {
    (void)ac;
    (void)av;
    t_tiny tiny;
    // char *read;
    while (1)
    {
        // Get prompt with color
        char *prompt = signal_things();
        // Read the input line with colored prompt
        tiny.line = readline(prompt);
        free(prompt); // Free the prompt memory after usage
        to_lexer(tiny.line);
        // print_lexer();

    }
}