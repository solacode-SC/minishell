#include "minishell.h"


void add_token(t_token **head, t_token *new_token) {
    if (*head == NULL) {
        *head = new_token;
    } else {
        t_token *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_token;
        new_token->prev = current;
    }
}

t_token *create_token(const char *value, TokenType type) {
    t_token *new_token = malloc(sizeof(t_token));
    if (!new_token) {
        perror("Failed to allocate memory for token");
        return NULL;
    }
    new_token->Value = strdup(value);
    new_token->type = type;
    new_token->prev = NULL;
    new_token->next = NULL;
    return new_token;
}

void free_tokens(t_token *head) {
    t_token *current = head;
    while (current) {
        t_token *next = current->next;
        free(current->Value);
        free(current);
        current = next;
    }
}

void print_tokens(t_token *head) {
    t_token *current = head;
    while (current) {
        const char *type_str;
        switch (current->type) {
            case WORD: type_str = "WORD"; break;
            case PIPE: type_str = "PIPE"; break;
            case REDIRECT_IN: type_str = "REDIRECT_IN"; break;
            case REDIRECT_OUT: type_str = "REDIRECT_OUT"; break;
            case REDIRECT_APPEND: type_str = "REDIRECT_APPEND"; break;
            case HEREDOC: type_str = "HEREDOC"; break;
            case ENV_VAR: type_str = "ENV_VAR"; break;
            case END: type_str = "END"; break;
            case ESPC: type_str = "ESPC"; break;
            default: type_str = "UNKNOWN"; break;
        }
        printf("Value: %s, Type: %s\n", current->Value, type_str);
        current = current->next;
    }
}

// append to liked list


// remove from

// print all nodes