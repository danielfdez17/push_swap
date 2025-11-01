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
INCLUDES = -I ./inc/headers -I ./inc/libft/inc/headers/

# Objects dir
OBJ_DIR = ./src/obj/

# Sources files
PUSH_SWAP_DIR = ./src/
PUSH_SWAP_SRCS = $(shell ls $(PUSH_SWAP_DIR) | grep -E ".+\.c")
SRCS = $(PUSH_SWAP_SRCS)

# Creating object files
OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))

# LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

# RULES
# Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@clear
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Compiling push_swap"

test:
# 	@echo ls $(SRCS)
	@echo ls $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@echo "Compiling libft"

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
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Removing $(NAME)"

# Rebuilds the program/library
re: fclean all
	@echo "Rebuilding $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR) re
	@echo "Rebuilding $(NAME)"

NUMBERS = ./files/500_1

run: all
	clear
	./$(NAME) $(shell cat $(NUMBERS))

valgrind: all
	clear
	valgrind ./$(NAME) $(shell cat $(NUMBERS))

debug: all
	clear
	gdb ./$(NAME)

# Protects all rules from files with same name
.PHONY: all obj clean fclean re run valgrind debug
