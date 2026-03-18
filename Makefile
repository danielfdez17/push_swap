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
		printf "%b [%sms]\n" "$(strip $(2))" "$$elapsed_ms"; \
	fi; \
	exit $$status
endef

# * Compiler and flags
MYCC = cc
WARNING_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fsanitize=address
PUSHSWAP_FLAGS = -D SORT_ALGO=1 -D DEBUG_MODE=false
# MYCFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CPPFLAGS = -I./inc/headers -I./inc/libft/inc -MMD -MP

# * Build type (make BUILD_TYPE=debug for debug mode)
BUILD_TYPE ?= release

ifeq ($(BUILD_TYPE),debug)
	OPT_FLAGS = -g3 -ggdb -O0 # Optimize for debugging, not for speed
else
	OPT_FLAGS = -O2 # Optimize for speed, but not at the cost of debuggability
endif

CFLAGS = $(WARNING_FLAGS) $(OPT_FLAGS) $(PUSHSWAP_FLAGS)

# * Removal
RM = rm -rf

NOPRINT += --no-print-directory

# * Sources files
PUSH_SWAP_SOURCES_DIR = ./src/
PUSH_SWAP_SRCS =	\
					src/args_processing.c \
					src/best_move.c \
					src/bucket.c \
					src/counting.c \
					src/errors.c \
					src/main.c \
					src/push.c \
					src/radix.c \
					src/reverse_rotate.c \
					src/rotate_utils.c \
					src/rotate.c \
					src/selection.c \
					src/sort.c \
					src/stack_utils.c \
					src/stack.c \
					src/swap.c \
					src/utils.c

PUSH_SWAP_BONUS_SRCS =	\
						src/args_processing.c \
						src/best_move.c \
						src/errors.c \
						src/executer_bonus.c \
						src/main_bonus.c \
						src/moves_bonus.c \
						src/push.c \
						src/reverse_rotate.c \
						src/rotate_utils.c \
						src/rotate.c \
						src/stack_utils.c \
						src/stack.c \
						src/swap.c \
						src/utils.c

SRCS = $(PUSH_SWAP_SRCS)
BONUS_SRCS = $(PUSH_SWAP_BONUS_SRCS)

# * Include files
INCLUDES_DIR = ./inc/headers

# * Creating object files
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_SRCS:.c=.o))
DEPS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.d))
DEPS += $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_SRCS:.c=.d))
-include $(DEPS)
# OBJS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_SRCS:.c=.o))
# BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRCS:.c=.o))

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

# ! RULES

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ? 🧩 Compiles the whole program/library
all: #obj $(NAME)
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
bonus: all #obj $(BONUS_NAME) all
	@build_plan="$$($(MAKE) -s -n $(BONUS_NAME) $(NOPRINT) 2>&1)"; status=$$?; \
	if [ $$status -ne 0 ]; then \
		printf "%s\n" "$$build_plan"; \
		exit $$status; \
	elif [ -n "$$build_plan" ]; then \
		$(MAKE) $(BONUS_NAME) $(NOPRINT); \
	else \
		printf "%b\n" "$(BONUS) $(CYAN)Everything is up to date$(RESET)"; \
	fi

# ? Links a .c (and .h if needed) to its .o file
# $(OBJS): %.o: %.c
# 	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
# $(BONUS_OBJS): %.o: %.c
# 	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
# $(OBJ_DIR)%.o: $(PUSH_SWAP_SOURCES_DIR)%.c
# 	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

# $(BONUS_OBJ_DIR)%.o: $(PUSH_SWAP_SOURCES_DIR)%.c
# 	@$(MYCC) $(MYCFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

# ? 🔄 Updates the submodules
update:
	@echo "Updating submodules...";
	@git submodule update --init --recursive --remote
	@echo "Submodules updated!"

$(NAME): $(LIBFT) $(OBJS)
	$(call RUN_AND_LOG,$(MYCC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFT) -o $@,$(PUSH_SWAP) $(BUILT))
# 	@$(MYCC) $(MYCFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)
# 	@echo "$(PUSH_SWAP) $(BUILT)"

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(call RUN_AND_LOG,$(MYCC) $(CFLAGS) $(CPPFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@,$(BONUS) $(BUILT))
# 	@$(MYCC) $(MYCFLAGS) $(HEADERS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
# 	@echo "$(BONUS) $(BUILT)"

# ? 🧹 Removes the object files
clean:
	$(call RUN_AND_LOG,$(MAKE) -C $(LIBFT_DIR) clean $(NOPRINT); $(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR),$(PUSH_SWAP) $(OBJS_REMOVED))
# 	@$(RM) $(OBJS)
# 	@$(RM) $(BONUS_OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR) clean $(NOPRINT)
# 	@echo "$(PUSH_SWAP) $(OBJS_REMOVED)"


# ? 🗑️ Removes both object and executable files
fclean: #clean
	$(call RUN_AND_LOG,$(MAKE) -C $(LIBFT_DIR) fclean $(NOPRINT); $(MAKE) clean $(NOPRINT); $(RM) $(NAME) $(BONUS_NAME),$(PUSH_SWAP) $(REMOVED))
# 	@$(RM) $(NAME)
# 	@$(RM) $(BONUS_NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean $(NOPRINT)
# 	@echo "$(PUSH_SWAP) $(REMOVED)"

# ? 🔁 Rebuilds the program/library
re: #fclean all
	$(call RUN_AND_LOG,$(MAKE) fclean $(NOPRINT); $(MAKE) all $(NOPRINT),$(PUSH_SWAP) $(REBUILT))
# 	@$(MAKE) -C $(LIBFT_DIR) re $(NOPRINT)
# 	@echo "$(PUSH_SWAP) $(REBUILT)"

# ? 🔁 Rebuilds the bonus program
rebonus: #fclean bonus
	$(call RUN_AND_LOG,$(MAKE) -C $(LIBFT_DIR) re $(NOPRINT); echo "$(BONUS) $(REBUILT)",$(BONUS) $(REBUILT))
# 	@$(MAKE) -C $(LIBFT_DIR) re $(NOPRINT)
# 	@echo "$(BONUS) $(REBUILT)"

# ? 🧪 Checks the code with norminette
norminette:
	$(call RUN_AND_LOG,clear; $(MAKE) -C $(LIBFT_DIR) norminette $(NOPRINT); norminette $(INCLUDES_DIR) $(PUSH_SWAP_SOURCES_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)",$(PUSH_SWAP) $(BLUE)Norminette checked!$(RESET))
# 	@clear
# 	@$(MAKE) -C $(LIBFT_DIR) norminette $(NOPRINT)
# 	@norminette $(INCLUDES_DIR) $(PUSH_SWAP_SOURCES_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)"

# ? 🧪 Runs the tests
tests: #all
	$(call RUN_AND_LOG,clear; echo "Running tests..."; ARG='4 67 3 87 23'; ./$(NAME) $$ARG | ./$(BONUS_NAME) $$ARG; ARG='4 67 3 87 23'; ./push_swap $$ARG | ./checker $$ARG,$(PUSH_SWAP) $(GREEN)Tests completed!$(RESET))
# 	@echo "Running tests..."
# 	@$(shell ARG='4 67 3 87 23'; ./$(NAME) $ARG | ./$(BONUS_NAME) $ARG)
# 	@$(shell ARG='4 67 3 87 23'; ./push_swap $ARG | ./checker $ARG)

# ? 🧪 Runs the program with a test case
run: #bonus
	$(call RUN_AND_LOG,clear; echo "Running program..."; ./$(NAME) `seq -10 10 | shuf | head -n 10 | tr "\n" " "`; echo "Running bonus..."; ./$(BONUS_NAME) `seq -10 10 | shuf | head -n 10 | tr "\n" " "`,$(PUSH_SWAP) $(GREEN)Run completed!$(RESET))
# 	@clear
# 	./$(NAME) `seq -10 10 | shuf | head -n 10 | tr "\n" " "`

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

.DEFAULT_GOAL := all
