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
NAME=push_swap

# Source files
SRCS = main.c

# Include files
# INCS = ft_printf.h

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CCW = cc -Wall -Wextra -Werror

# Removal
RM = rm -f

# Archiver
# AR = ar -rcs

# Links a .c (and .h if needed) to its .o file
%.o: %.c
	$(CCW) -c $< -o $@

# Compiles the whole program/library
all: $(MAKE) -C ./libft/Makefile $(NAME)

$(NAME): $(OBJS)
	$(CCW) $(SRCS) -o $(NAME)

# Removes the object files
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Removes both object and executable files
fclean: clean
	$(RM) $(NAME)

# Rebuilds the program/library
re: fclean all

# Protects all rules from files with same name
.PHONY: all clean fclean re rebonus bonus
