
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>

// structs
typedef enum {
    WORD = 0,          // Command or argument
    PIPE = 1,          // '|'
    REDIRECT_IN = 2,   // '<'
    REDIRECT_OUT = 3,  // '>'
    REDIRECT_APPEND = 4, // '>>'
    HEREDOC = 5,       // '<<'
    ENV_VAR = 6,       // Environment variable
    END = 7,           // End of input
    ESPC = 8           //ESPACE
} TokenType;

typedef struct s_token {
    char            *Value;
    TokenType       type;
    struct s_token  *prev;
    struct s_token  *next;
} t_token;

// Define the shell state structure
typedef struct {
    char *line;
    int exit;
    int ret;
    // Add other members as needed
} t_tiny;

typedef struct	s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;



// all signals here
char* signal_things();

// all linked lists here
void add_token(t_token **head, t_token *new_token);
t_token *create_token(const char *value, TokenType type);
void free_tokens(t_token *head);
void print_tokens(t_token *head);
// all lexer here
void to_lexer();
void print_lexer();