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

# * Program name
NAME = push_swap

# * Utils
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
RESET = \033[0m
PUSH_SWAP = $(MAGENTA)[$(NAME)]$(RESET)
BUILT = $(GREEN)Built$(RESET)
OBJS_REMOVED = $(RED)Object files removed $(RESET)
REMOVED = $(RED)Removed $(RESET)
REBUILT = $(YELLOW)Rebuilt $(RESET)

# * Sources files
PUSH_SWAP_DIR = ./src/
PUSH_SWAP_SRCS =	counting.c \
					errors.c \
					init_stack.c \
					main.c \
					push.c \
					radix.c \
					reveverse_rotate.c \
					rotate.c \
					selection.c \
					sort.c \
					stack_utils.c \
					stack_utils2.c \
					swap.c

# * Objects dir
OBJ_DIR = ./src/obj/

SRCS = $(PUSH_SWAP_SRCS)

# * Includes
HEADERS = -I ./inc/headers -I ./inc/libft/inc/headers/

# * Creating object files
OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))

# * Compilation
MYCC = cc
MYCFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# * Removal
RM = rm -f

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

MAKEFLAGS += --no-print-directory

# ! RULES
# ? Compiles the whole program/library
all: update obj $(NAME)

# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

# ? Creates the objects directory if it doesn't exist
obj:
	@mkdir -p $(OBJ_DIR)

# ? Updates the submodules
update:
	@git submodule update --init --recursive

$(NAME): $(OBJS) $(LIBFT)
	@$(MYCC) $(MYCFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(PUSH_SWAP) $(BUILT)"

# ? Removes the object files
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(OBJS_REMOVED)"

# ? Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(REMOVED)"

# ? Rebuilds the program/library
re: fclean all
	@$(MAKE) -C $(LIBFT_DIR) re $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(REBUILT)"

norminette:
	@clear
	@$(MAKE) -C $(LIBFT_DIR) norminette $(MAKEFLAGS)
	@norminette $(PUSH_SWAP_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)"

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all         - Compiles the whole program"
	@echo "  obj         - Creates the objects directory if it doesn't exist"
	@echo "  clean       - Removes the object files"
	@echo "  fclean      - Removes both object and executable files"
	@echo "  re          - Rebuilds the program"
	@echo "  update       - Updates the submodules"
	@echo "  norminette   - Checks the code with norminette"
	@echo "  help         - Displays this help message"

.PHONY: obj update all clean fclean re help

.DEFAULT: all
