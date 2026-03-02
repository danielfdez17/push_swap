# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2025/11/03 13:17:15 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * Utils
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m
OK = $(GREEN)[OK]$(RESET)

# * Program name
NAME = push_swap

# * Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# * Removal
RM = rm -f

# * Includes
INCLUDES = -I ./inc/headers -I ./inc/libft/inc/headers/

# * Objects dir
OBJ_DIR = ./src/obj/

# * Sources files
PUSH_SWAP_DIR = ./src/
PUSH_SWAP_SRCS = $(shell ls $(PUSH_SWAP_DIR) | grep -E ".+\.c")
SRCS = $(PUSH_SWAP_SRCS)

# * Creating object files
OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

MAKEFLAGS += --no-print-directory

# ! RULES
# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(OK) push_swap $(RESET)"


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@echo "$(OK) libft $(RESET)"

# ? Compiles the whole program/library
all: obj $(NAME)

# ? Creates the objects directory if it doesn't exist
obj:
	@mkdir -p $(OBJ_DIR)

# ? Removes the object files
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean $(MAKEFLAGS)
	@echo "$(OK) $(RED) Removing .o files $(RESET)"

# ? Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean $(MAKEFLAGS)
	@echo "$(OK) $(RED) Removing $(NAME) $(RESET)"

# ? Rebuilds the program/library
re: fclean all
	@$(MAKE) -C $(LIBFT_DIR) re $(MAKEFLAGS)
	@echo "$(OK) $(NAME)"

NUMBERS = ./files/10_1

run: all
	clear
# 	./$(NAME) $(NUMBERS)
# 	./$(NAME) $(shell cat $(NUMBERS))
	./$(NAME) $(shell cat $(NUMBERS)) | wc -l

valgrind: all
	clear
	valgrind ./$(NAME) $(shell cat $(NUMBERS))

debug: all
	clear
	gdb ./$(NAME)

# Protects all rules from files with same name
.PHONY: all obj clean fclean re run valgrind debug
