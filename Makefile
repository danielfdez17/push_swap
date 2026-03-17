# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2026/03/13 08:14:31 by daniel           ###   ########.fr        #
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

# * Timer helper
define RUN_AND_LOG
	@start_ms=$$(date +%s%3N); \
	$(1); status=$$?; \
	end_ms=$$(date +%s%3N); \
	elapsed_ms=$$((end_ms - start_ms)); \
	if [ $$status -eq 0 ]; then \
		printf "%b [%sms]\n" "$(2)" "$$elapsed_ms"; \
	fi; \
	exit $$status
endef

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
					selection.c \
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
INCLUDES_DIR = ./inc/

# * Creating object files
OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRCS:.c=.o))

# * Compilation
MYCC = cc
MYCFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -D SORT_ALGO=1 -D DEBUG_MODE=false

# * Removal
RM = rm -f

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

NOPRINT += --no-print-directory

# ! RULES
# ? 🧩 Compiles the whole program/library
all: $(OBJ_DIR)
	@build_plan="$$($(MAKE) -s -n $(NAME) $(NOPRINT) 2>&1)"; status=$$?; \
	if [ $$status -ne 0 ]; then \
		printf "%s\n" "$$build_plan"; \
		exit $$status; \
	elif [ -n "$$build_plan" ]; then \
		$(MAKE) $(NAME) $(NOPRINT); \
	else \
		printf "%b\n" "$(PUSH_SWAP) $(CYAN)Everything is up to date$(RESET)"; \
	fi

# ? 🔨 Compiles the bonus program
bonus: $(OBJ_DIR) $(BONUS_NAME) all

# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

# ? 📁 Creates the objects directory if it doesn't exist
$(OBJ_DIR) $(BONUS_OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BONUS_OBJ_DIR)

# ? 🔄 Updates the submodules
update:
	$(call RUN_AND_LOG,git submodule update --init --recursive --remote --merge,$(GREEN)Submodules updated.$(RESET))

$(NAME): $(OBJS) $(LIBFT)
	$(call RUN_AND_LOG,$(MYCC) $(MYCFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME),$(PUSH_SWAP) $(BUILT))

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(call RUN_AND_LOG,$(MYCC) $(MYCFLAGS) $(HEADERS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME),$(BONUS) $(BUILT))

# ? 🧹 Removes the object files
clean:
	$(call RUN_AND_LOG,$(RM) $(OBJS); $(RM) $(BONUS_OBJS); $(MAKE) -C $(LIBFT_DIR) clean $(NOPRINT),$(PUSH_SWAP) $(OBJS_REMOVED))


# ? 🗑️ Removes both object and executable files
fclean:
	$(call RUN_AND_LOG,$(MAKE) clean $(NOPRINT); $(RM) $(NAME); $(RM) $(BONUS_NAME); $(MAKE) -C $(LIBFT_DIR) fclean $(NOPRINT),$(PUSH_SWAP) $(REMOVED))

# ? 🔁 Rebuilds the program/library
re: #fclean all
	$(call RUN_AND_LOG,$(MAKE) fclean $(NOPRINT); $(MAKE) all $(NOPRINT); $(MAKE) -C $(LIBFT_DIR) all $(NOPRINT),$(PUSH_SWAP) $(REBUILT))

# ? 🔁 Rebuilds the bonus program
rebonus: #fclean bonus
	$(call RUN_AND_LOG,$(MAKE) fclean $(NOPRINT); $(MAKE) bonus $(NOPRINT); $(MAKE) -C $(LIBFT_DIR) all $(NOPRINT),$(BONUS) $(REBUILT))

# ? 🧪 Checks the code with norminette
norminette:
	$(call RUN_AND_LOG,clear; $(MAKE) -C $(LIBFT_DIR) norminette $(NOPRINT); norminette $(INCLUDES_DIR) $(PUSH_SWAP_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)",$(PUSH_SWAP) $(GREEN)Norminette checked$(RESET))

# ? 🧪 Runs the tests
tests: #bonus
	$(call RUN_AND_LOG,$(MAKE) bonus $(NOPRINT); ARG='4 67 3 87 23'; ./$(NAME) $$ARG | ./$(BONUS_NAME) $$ARG; ARG='4 67 3 87 23'; ./push_swap $$ARG | ./checker $$ARG,$(PUSH_SWAP) $(GREEN)Tests finished$(RESET))

# ? 🧪 Runs the program with a test case
run: #bonus
	$(call RUN_AND_LOG,$(MAKE) bonus $(NOPRINT); clear; ./$(NAME) `seq -10 10 | shuf | head -n 10 | tr "\n" " "`,$(PUSH_SWAP) $(GREEN)Run finished$(RESET))

# ? ❓ Displays this help message
help:
	@start_ms=$$(date +%s%3N); \
	awk '\
		BEGIN { blue = "\033[0;34m"; green = "\033[0;32m"; reset = "\033[0m"; yellow = "\033[0;33m"; print yellow "Usage: make [target]"; print "Targets:" } \
		/^# \?/ { desc = substr($$0, 5); next } \
		/^$$/ { desc = ""; next } \
		/^[a-zA-Z0-9][a-zA-Z0-9_.-]*:/ { \
			target = $$1; \
			sub(/:.*/, "", target); \
			if (target !~ /^\./) \
				printf "  " blue "%-12s" reset green "%s" reset "\n", target, desc; \
			desc = ""; \
		}' $(firstword $(MAKEFILE_LIST)); \
	end_ms=$$(date +%s%3N); \
	elapsed_ms=$$((end_ms - start_ms)); \
	printf "$(BLUE)[help]$(RESET) Displayed [%sms]\n" "$$elapsed_ms"


# define BANNER
# 	@echo ""
# 	@echo "$(BLUE)"
# 	@echo "╔══════════════════════════════════════════════════════════╗"
# 	@echo "║  ____  _   _ ____  _   _   ____ __        ___    ____    ║"
# 	@echo "║ |  _ \| | | / ___|| | | | / ___|\\ \      / / \  |  _ \   ║"
# 	@echo "║ | |_) | | | \___ \| |_| | \___ \\ \ \ /\ / / _ \ | |_) |  ║"
# 	@echo "║ |  __/| |_| |___) |  _  |  ___) | \ V  V / ___ \|  __/   ║"
# 	@echo "║ |_|    \___/|____/|_| |_| |____/   \_/\_/_/   \_\_|      ║"
# 	@echo "║                                                          ║"
# 	@echo "╚══════════════════════════════════════════════════════════╝"
# 	@echo "$(RESET)"
# endef

# banner:
# 	$(BANNER)

.PHONY: obj update all clean fclean re help tests run

.DEFAULT_GOAL := all
