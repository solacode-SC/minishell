# Variables
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude
LIBS = -lreadline
SRCS = main.c lexer/ft_lexer.c ft_tools/ft_signals.c ft_tools/ft_linked.c
OBJS = $(SRCS:.c=.o)
NAME = minishell

# Rules
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
