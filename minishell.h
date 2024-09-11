
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum {
    WORD,          // Command or argument
    PIPE,          // '|'
    REDIRECT_IN,   // '<'
    REDIRECT_OUT,  // '>'
    REDIRECT_APPEND, // '>>'
    HEREDOC,       // '<<'
    ENV_VAR,       // Environment variable, e.g., $PATH
    END            // End of input
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

// Define the shell state structure
typedef struct {
    char *line;
    int exit;
    int ret;
    // Add other members as needed
} t_tiny;
