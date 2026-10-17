# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2026/10/17 13:13:29 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /usr/bin/bash
.SHELLFLAGS := -ec

# * Program name
NAME = push_swap
BONUS_NAME = checker

# * Utils
GREEN := $(shell printf '\033[0;32m')
YELLOW := $(shell printf '\033[0;33m')
RESET := $(shell printf '\033[0m')
MAGENTA := $(shell printf '\033[0;35m')
CYAN := $(shell printf '\033[0;36m')
RED := $(shell printf '\033[0;31m')
SUCCESS := $(GREEN)✓
FAIL := $(RED)✗
INFO := $(CYAN)ℹ
WARN := $(YELLOW)⚠

PRINT_BANNER := ./scripts/bash/print_banner.sh
PRINT_SUCCESS := ./scripts/bash/print_success.sh
PRINT_FAIL := ./scripts/bash/print_fail.sh
PRINT_INFO := ./scripts/bash/print_info.sh
PRINT_WARN := ./scripts/bash/print_warning.sh

PUSH_SWAP = $(MAGENTA)[$(NAME)]$(RESET)
BONUS = $(CYAN)[$(BONUS_NAME)]$(RESET)
BUILT = $(GREEN)Built$(RESET)
OBJS_REMOVED = $(RED)Object files removed $(RESET)
REMOVED = $(RED)Removed $(RESET)
REBUILT = $(YELLOW)Rebuilt $(RESET)

# * Time a command and print a message on success
RUN_AND_LOG := ./scripts/bash/run_and_log.sh

# * Compiler and flags
MYCC = cc
WARNING_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fsanitize=address
PUSHSWAP_FLAGS = -D DEBUG_MODE=false
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
					src/counting.c \
					src/errors.c \
					src/main.c \
					src/push.c \
					src/reverse_rotate.c \
					src/rotate_utils.c \
					src/rotate.c \
					src/sort.c \
					src/stack_utils.c \
					src/stack.c \
					src/swap.c \
					src/utils.c

SORT_ALGO ?= 0

ifeq ($(SORT_ALGO),0)
	PUSH_SWAP_SRCS += src/bucket.c
else ifeq ($(SORT_ALGO),1)
	PUSH_SWAP_SRCS += src/radix.c
else
	PUSH_SWAP_SRCS += src/selection.c
endif


PUSH_SWAP_BONUS_SRCS =	\
						src/args_processing.c \
						src/best_move.c \
						src/counting.c \
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

# * LIBFT
LIBFT_DIR = ./inc/libft/
LIBFT = ./inc/libft/libft.a

# ! RULES
# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(MYCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ── Push Swap
.PHONY: all
all: ## Compiles the whole program
	@build_plan="$$($(MAKE) -s -n $(NAME) $(NOPRINT) 2>&1)"; status=$$?; \
	if [ $$status -ne 0 ]; then \
		printf "%s\n" "$$build_plan"; \
		exit $$status; \
	elif [ -n "$$build_plan" ]; then \
		$(MAKE) $(NAME) $(NOPRINT); \
	else \
		printf "%b\n" "$(PUSH_SWAP) $(CYAN)Everything is up to date$(RESET)"; \
	fi

.PHONY: bonus
bonus: all ## Compiles the bonus program
	@build_plan="$$($(MAKE) -s -n $(BONUS_NAME) $(NOPRINT) 2>&1)"; status=$$?; \
	if [ $$status -ne 0 ]; then \
		printf "%s\n" "$$build_plan"; \
		exit $$status; \
	elif [ -n "$$build_plan" ]; then \
		$(MAKE) $(BONUS_NAME) $(NOPRINT); \
	else \
		printf "%b\n" "$(BONUS) $(CYAN)Everything is up to date$(RESET)"; \
	fi

.PHONY: $(LIBFT)
$(LIBFT): ## Compiles the libft library
	@$(MAKE) -C $(LIBFT_DIR) all

.PHONY: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(BUILT)" -c '$(MYCC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFT) -o $@'

.PHONY: $(BONUS_NAME)
$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)

	@$(RUN_AND_LOG) -m "$(BONUS) $(BUILT)" -c '$(MYCC) $(CFLAGS) $(CPPFLAGS) $(BONUS_OBJS) $(LIBFT) -o $@'

.PHONY: clean
clean: ## Removes the object files
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(OBJS_REMOVED)" -c '$(MAKE) -C $(LIBFT_DIR) clean $(NOPRINT); $(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)'

.PHONY: fclean
fclean: ## Removes both object and executable files
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(REMOVED)" -c '$(MAKE) -C $(LIBFT_DIR) fclean $(NOPRINT); $(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR) $(NAME) $(BONUS_NAME)'

.PHONY: re
re: ## Rebuilds the program/library
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(REBUILT)" -c '$(MAKE) fclean $(NOPRINT); $(MAKE) all $(NOPRINT)'

.PHONY: rebonus
rebonus: ## Rebuilds the bonus program
	@$(RUN_AND_LOG) -m "$(BONUS) $(REBUILT)" -c '$(MAKE) fclean $(NOPRINT); $(MAKE) bonus $(NOPRINT)'

.PHONY: norminette
norminette: ## Checks the code with norminette
	@$(PRINT_BANNER) "Checking code with Norminette"
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(BLUE)Norminette checked!$(RESET)" -c '$(MAKE) -C $(LIBFT_DIR) norminette $(NOPRINT); norminette $(INCLUDES_DIR) $(PUSH_SWAP_SOURCES_DIR) | grep Error || echo "$(PUSH_SWAP) $(GREEN)Norminette passed!$(RESET)"'
	@$(PRINT_SUCCESS) "Norminette checked successfully!"

.PHONY: tests
tests: ## Runs the tests
	@$(RUN_AND_LOG) -m "$(PUSH_SWAP) $(GREEN)Tests completed!$(RESET)" -c 'clear; $(MAKE) -s bonus; ARG=`seq -10 10 | shuf | head -n 10 | tr "\n" " "`;echo "Running tests with $$ARG"; ./$(NAME) $$ARG | ./$(BONUS_NAME) $$ARG'

.PHONY: run_push_swap_tester
run_push_swap_tester: ## Runs a single test with random arguments
	bash ./scripts/42/push_swap/push_swap_tester.sh 100 500

.PHONY: help
# ── Utils
help: ## Show available targets
	@$(PRINT_BANNER) "Available Makefile Targets"
	@LC_ALL=C.UTF-8 awk '\
		function trim(s) { \
			sub(/^[[:space:]]+/, "", s); \
			sub(/[[:space:]]+$$/, "", s); \
			return s \
		} \
		/^# ──[[:space:]]+/ { \
			title = $$0; \
			sub(/^# ──[[:space:]]+/, "", title); \
			sub(/[[:space:]]*─+[[:space:]]*$$/, "", title); \
			title = trim(title); \
			n++; kind[n] = "section"; text[n] = title; \
			next \
		} \
		/^[a-zA-Z_-]+:.*## / { \
			name = $$0; sub(/:.*/, "", name); \
			msg = $$0; sub(/^[^#]*## /, "", msg); \
			n++; kind[n] = "target"; names[n] = name; msgs[n] = msg; \
			if (length(name) > name_width) name_width = length(name); \
			next \
		} \
		END { \
			for (i = 1; i <= n; i++) \
				if (kind[i] == "target") { \
					line = 2 + name_width + 1 + length(msgs[i]); \
					if (line > line_width) line_width = line \
				} \
			for (i = 1; i <= n; i++) \
				if (kind[i] == "section") { \
					label = "── " text[i] " "; \
					pad = line_width - length(label); \
					if (pad < 1) pad = 1; \
					dashes = ""; \
					for (j = 0; j < pad; j++) dashes = dashes "─"; \
					printf "%s%s\n", label, dashes \
				} else \
					printf "  $(CYAN)%-*s$(RESET) %s\n", name_width, names[i], msgs[i] \
		}' Makefile

.PHONY: update-submodules
update-submodules: ## Update git submodules
	@$(PRINT_BANNER) "Updating Git Submodules"
	@git submodule update --init --recursive --remote
	@$(PRINT_SUCCESS) "Git submodules updated successfully!"

.DEFAULT_GOAL := all
