# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2025/10/25 11:55:52 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Library name
NAME = push_swap

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS += -fsanitize=address

# Removal
RM = rm -f

# Includes
INCLUDES = -I ./inc/headers

# Objects dir
OBJ_DIR = ./src/obj/

# Sources files
SRCS_DIR = ./src/
SRCS = \
	list.c \
	push.c \
	push_swap.c \
	reveverse_rotate.c \
	rotate.c \
	swap.c

NUMBERS = 38 27 43 10

# Creating object files
SOURCES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# RULES
# Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@clear
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "Compiling push_swap"

# Compiles the whole program/library
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# Removes the object files
clean:
	@$(RM) $(OBJS)
	@echo "Removing .o files"

# Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $(NAME)"

# Rebuilds the program/library
re: fclean all
	@echo "Rebuilding $(NAME)"

run: all
	clear
	./$(NAME) $(NUMBERS)

valgrind: all
	clear
	valgrind ./$(NAME) $(NUMBERS)

debug: all
	clear
	gdb ./$(NAME)

# Protects all rules from files with same name
.PHONY: all obj clean fclean re run valgrind debug
