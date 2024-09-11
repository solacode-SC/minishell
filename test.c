#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>



// Function to return a prompt string in green
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

int main(int argc, char **argv, char **envp) {
    t_tiny tiny;
    char *read;

    // Environment check
    if (argc != 1 || envp == NULL || *envp == NULL) {
        fprintf(stderr, "Error: No environment found. Exiting...\n");
        return EXIT_FAILURE;
    }

    // Initialize the shell environment
    init(&tiny, envp);

    while (tiny.exit == 0) {
        // Get prompt with color
        char *prompt = signal_things();

        // Read the input line with colored prompt
        tiny.line = readline(prompt);
        free(prompt); // Free the prompt memory after usage

        if (tiny.line == NULL) {
            break; // Exit on EOF
        }

        // Skip empty lines
        if (strlen(tiny.line) == 0) {
            free(tiny.line);
            continue;
        }

        // Add input to history
        add_history(tiny.line);

        // Check syntax and execute command if valid
        if (!check_syntax(tiny.line)) {
            parse(&tiny);
            exec(&tiny);
        }

        // Free the input line
        free(tiny.line);
    }

    // Clean up and exit
    free_all(&tiny);
    return tiny.ret;
}
