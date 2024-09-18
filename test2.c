
// Function to create a token
Token* create_token(TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    if (!token) {
        perror("Failed to allocate token");
        exit(EXIT_FAILURE);
    }
    token->type = type;
    token->value = strdup(value);  // Duplicates string value
    if (!token->value) {
        perror("Failed to duplicate string");
        exit(EXIT_FAILURE);
    }
    return token;
}

// Function to add token to the tokens array
void add_token(Token** tokens, int* count, TokenType type, const char* value) {
    tokens[*count] = create_token(type, value);
    (*count)++;
}

// Function to find an environment variable by its name in envp
char* get_env_var(char** envp, const char* var_name) {
    int len = strlen(var_name);
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=') {
            return envp[i] + len + 1; // Return the value after the '='
        }
    }
    return NULL;
}

// Lexer function to tokenize input
Token** lexer(const char* input, char** envp) {
    Token** tokens = (Token**)malloc(sizeof(Token*) * 1024); // Dynamic array of tokens
    if (!tokens) {
        perror("Failed to allocate tokens array");
        exit(EXIT_FAILURE);
    }
    int token_count = 0;
    int i = 0;
    char buffer[1024];
    int buf_index = 0;

    while (input[i] != '\0') {
        char current = input[i];

        // Skip whitespace
        if (isspace(current)) {
            i++;
            continue;
        }

        // Handle pipes
        if (current == '|') {
            add_token(tokens, &token_count, PIPE, "|");
            i++;
            continue;
        }

        // Handle redirections
        if (current == '>') {
            if (input[i+1] == '>') { // '>>'
                add_token(tokens, &token_count, REDIRECT_APPEND, ">>");
                i += 2;
            } else { // '>'
                add_token(tokens, &token_count, REDIRECT_OUT, ">");
                i++;
            }
            continue;
        }

        if (current == '<') {
            if (input[i+1] == '<') { // '<<'
                add_token(tokens, &token_count, HEREDOC, "<<");
                i += 2;
            } else { // '<'
                add_token(tokens, &token_count, REDIRECT_IN, "<");
                i++;
            }
            continue;
        }

        // Handle environment variables
        if (current == '$') {
            buf_index = 0;
            i++; // Skip '$'
            while (isalnum(input[i]) || input[i] == '_') {
                buffer[buf_index++] = input[i++];
            }
            buffer[buf_index] = '\0';

            // Get the environment variable value using envp
            char* env_value = get_env_var(envp, buffer);
            if (env_value) {
                add_token(tokens, &token_count, ENV_VAR, env_value);
            } else {
                add_token(tokens, &token_count, ENV_VAR, "");
            }
            continue;
        }

        // Handle words (commands, filenames, arguments)
        buf_index = 0;
        while (!isspace(current) && current != '|' && current != '<' && current != '>' && current != '\0') {
            buffer[buf_index++] = current;
            current = input[++i];
        }
        buffer[buf_index] = '\0';
        add_token(tokens, &token_count, WORD, buffer);
    }

    // End the tokens list with a NULL pointer to mark the end
    tokens[token_count] = NULL;
    return tokens;
}

// Function to print tokens for debugging
void print_tokens(Token** tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token Type: %d, Value: %s\n", tokens[i]->type, tokens[i]->value);
    }
}

// Free allocated memory for tokens
void free_tokens(Token** tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]->value);
        free(tokens[i]);
    }
    free(tokens);
}

// / Function to return a prompt string in green
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
    // init(&tiny, envp);

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
            // exec(&tiny);
        }

        // Free the input line
        free(tiny.line);
    }

    // Clean up and exit
    free_all(&tiny);
    return tiny.ret;
}