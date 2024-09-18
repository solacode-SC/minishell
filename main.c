
#include "minishell.h"

char* signal_things() {
    // ANSI escape codes for green text and reset color
    const char* green = "\033[32m";
    const char* reset = "\033[0m";
    
    // Create a buffer for the prompt string
    char *prompt = (char *)malloc(50); // Adjust size as needed
    if (prompt == NULL) {
        perror("Failed to allocate memory for prompt");
        exit(EXIT_FAILURE);
    }
    
    // Format the prompt with green color
    snprintf(prompt, 50, "%sminishell> %s", green, reset);
    
    return prompt;
}

int main(int ac, char **av, char **envp) {
    t_tiny tiny;
    // char *read;
    while (1)
    {
        // Get prompt with color
        char *prompt = signal_things();
        // Read the input line with colored prompt
        tiny.line = readline(prompt);
        free(prompt); // Free the prompt memory after usage

        printf("%s\n", tiny.line);

    }
}