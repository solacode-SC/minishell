
#include "minishell.h"


int main(int ac, char **av, char **envp) {
    (void)ac;
    (void)av;
    t_tiny tiny;
    t_token *token_list = NULL; // Initialize the token list

    while (1) {
        char *prompt = signal_things();
        tiny.line = readline(prompt);
        free(prompt);

        if (tiny.line == NULL) {
            break; // Handle EOF or read error
        }

        to_lexer(tiny.line, &token_list);
        free(tiny.line); // Free the line

        // Print the token list
        print_tokens(token_list);

        // Clean up the token list when done
        free_tokens(token_list);
        token_list = NULL; // Reset the token list for the next input
    }

    return 0;
}
