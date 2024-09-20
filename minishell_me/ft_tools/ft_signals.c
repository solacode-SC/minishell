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