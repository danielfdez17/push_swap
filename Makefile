# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2026/03/06 19:24:18 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * Program name
NAME = push_swap
BONUS_NAME = checker

# * Utils
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
PUSH_SWAP = $(MAGENTA)[$(NAME)]$(RESET)
BONUS = $(CYAN)[$(BONUS_NAME)]$(RESET)
BUILT = $(GREEN)Built$(RESET)
OBJS_REMOVED = $(RED)Object files removed $(RESET)
REMOVED = $(RED)Removed $(RESET)
REBUILT = $(YELLOW)Rebuilt $(RESET)

# * Sources files
PUSH_SWAP_DIR = ./src/
PUSH_SWAP_SRCS =	args_processing.c \
					best_move.c \
					bucket.c \
					counting.c \
					errors.c \
					main.c \
					push.c \
					radix.c \
					reveverse_rotate.c \
					rotate_utils.c \
					rotate.c \
					sort.c \
					stack_utils.c \
					stack.c \
					swap.c \
					utils.c

PUSH_SWAP_BONUS_SRCS =	args_processing.c \
						best_move.c \
						errors.c \
						executer_bonus.c \
						main_bonus.c \
						moves_bonus.c \
						push.c \
						reveverse_rotate.c \
						rotate_utils.c \
						rotate.c \
						stack_utils.c \
						stack.c \
						swap.c \
						utils.c

# * Objects dir
OBJ_DIR = ./src/obj/
BONUS_OBJ_DIR = ./src/bonus_obj/

SRCS = $(PUSH_SWAP_SRCS)
BONUS_SRCS = $(PUSH_SWAP_BONUS_SRCS)

# * Includes
HEADERS = -I ./inc/headers -I ./inc/libft/inc/headers/

# * Creating object files
OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRCS:.c=.o))

# * Compilation
MYCC = cc
MYCFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -D DEBUG_MODE=false

# * Removal
RM = rm -f

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

MAKEFLAGS += --no-print-directory

# ! RULES
# ? 🧩 Compiles the whole program/library
all: update obj $(NAME)

# ? 🔨 Compiles the bonus program
bonus: update obj $(BONUS_NAME) all

# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

# ? 📁 Creates the objects directory if it doesn't exist
obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BONUS_OBJ_DIR)

# ? 🔄 Updates the submodules
update:
	@git submodule update --init --recursive

$(NAME): $(OBJS) $(LIBFT)
	@$(MYCC) $(MYCFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(PUSH_SWAP) $(BUILT)"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	@$(MYCC) $(MYCFLAGS) $(HEADERS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(BONUS) $(BUILT)"

# ? 🧹 Removes the object files
clean:
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(OBJS_REMOVED)"


# ? 🗑️ Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(REMOVED)"

# ? 🔁 Rebuilds the program/library
re: fclean all
	@$(MAKE) -C $(LIBFT_DIR) re $(MAKEFLAGS)
	@echo "$(PUSH_SWAP) $(REBUILT)"

# ? 🔁 Rebuilds the bonus program
rebonus: fclean bonus
	@$(MAKE) -C $(LIBFT_DIR) re $(MAKEFLAGS)
	@echo "$(BONUS) $(REBUILT)"

# ? 🧪 Checks the code with norminette
norminette:
	@clear
	@$(MAKE) -C $(LIBFT_DIR) norminette $(MAKEFLAGS)
	@norminette $(PUSH_SWAP_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)"

# ? 🧪 Runs the tests
tests: all
	@echo "Running tests..."
	@$(shell ARG='4 67 3 87 23'; ./$(NAME) $ARG | ./$(BONUS_NAME) $ARG)
	@$(shell ARG='4 67 3 87 23'; ./push_swap $ARG | ./checker $ARG)

# ? 🧪 Runs the program with a test case
run: bonus
	@clear
	./$(NAME) -6 2 4 -3 -5 -1

# ? ❓ Displays this help message
help:
	@awk '\
		BEGIN { blue = "\033[0;34m"; green = "\033[0;32m"; reset = "\033[0m"; yellow = "\033[0;33m"; print yellow "Usage: make [target]"; print "Targets:" } \
		/^# \?/ { desc = substr($$0, 5); next } \
		/^$$/ { desc = ""; next } \
		/^[a-zA-Z0-9][a-zA-Z0-9_.-]*:/ { \
			target = $$1; \
			sub(/:.*/, "", target); \
			if (target !~ /^\./) \
				printf "  " blue "%-12s" reset green "%s" reset "\n", target, desc; \
			desc = ""; \
		}' $(firstword $(MAKEFILE_LIST))

.PHONY: obj update all clean fclean re help tests run

.DEFAULT: all
