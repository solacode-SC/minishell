#include "minishell.h"

void to_lexer(char *line, t_token **token_list) {
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '|') {
            add_token(token_list, create_token("|", PIPE));
        } else if (line[i] == '>' && line[i + 1] == '>') {
            add_token(token_list, create_token(">>", REDIRECT_APPEND));
            i++; // Skip next character
        } else if (line[i] == '<' && line[i + 1] == '<') {
            add_token(token_list, create_token("<<", HEREDOC));
            i++; // Skip next character
        } else if (line[i] == '>') {
            add_token(token_list, create_token(">", REDIRECT_OUT));
        } else if (line[i] == '<') {
            add_token(token_list, create_token("<", REDIRECT_IN));
        } else if (line[i] == ' ') {
            add_token(token_list, create_token(" ", ESPC));
        } else {
            int start = i;
            while (line[i] != ' ' && line[i] != '\0' && line[i] != '|' && line[i] != '<' && line[i] != '>') {
                i++;
            }
            char cmd[256]; // Adjust size as needed
            snprintf(cmd, i - start + 1, "%s", line + start);
            add_token(token_list, create_token(cmd, WORD));
            continue; // Skip the increment at the end of the loop
        }
        i++; // Move to the next character
    }
}

