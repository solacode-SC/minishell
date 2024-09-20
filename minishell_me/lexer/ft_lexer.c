#include "minishell.h"

void to_lexer(char *line)
{
    int i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '|')
            printf("value = |,\n");
            else if (line[i] == '>' && line[i+1] == '>')
        {
            printf("value = >>,\n");
            i++;
        }
        else if (line[i] == '<' && line[i+1] == '<')
        {
            printf("value = <<,\n");
            i++;
        }
        else if (line[i] == '>')
            printf("value = >,\n");
        else if (line[i] == '<')
            printf("value = <,\n");
        else if (line[i] == ' ')
            printf("value = E,\n");
        else
        {
            while (line[i + 1] != ' ')
                i++;

            printf("value = cmd,\n");
        }
        i++;
    }

}