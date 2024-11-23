# Project details
name = minishell

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address 

# Directories
SRC_DIR = .
HEADER_DIR = header

# Source files
SRC = minishell.c \
      execution/apend_to_file.c \
      execution/check_build.c \
      execution/check_file.c \
      execution/exec_coammd.c \
      execution/execut_build.c \
      execution/execut_comand.c \
	  execution/execution.c \
      execution/ft_apend_struct.c \
      execution/ft_catstr.c \
      execution/ft_cd.c \
      execution/ft_check_path.c \
	  execution/ft_echo.c \
      execution/ft_env.c \
      execution/ft_exit.c \
	  execution/ft_expand_her.c \
      execution/ft_expending.c \
      execution/ft_export.c \
	  execution/ft_getenv.c \
      execution/ft_herdoc.c \
      execution/ft_setenv.c \
	  execution/ft_unset.c \
      execution/print_sort.c \
	  execution/set_env.c \
      parsing/lexer.c \
      parsing/parsing.c \
      tools/error.c \
      tools/ft_free.c \
      tools/ft_fun1.c \
      tools/ft_fun2.c \
      tools/ft_fun3.c \
      tools/ft_fun4.c \
      tools/ft_helper.c \
      tools/ft_signals.c \
      tools/ft_tools.c

# Object files
OBJ = $(SRC:%.c=%.o)

# Include headers
INC = -I $(HEADER_DIR)

# Targets
all: $(name)

$(name): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(name) -lreadline


# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(name)

re: fclean all
