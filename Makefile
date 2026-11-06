# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 17:27:31 by danfern3          #+#    #+#              #
#    Updated: 2026/11/06 17:27:57 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Entry point. Set the default goal before including modules so a target
# defined in mk/*.mk cannot become the default.
#
# Add a module by creating mk/<name>.mk and appending an include below.
.DEFAULT_GOAL := help

include mk/config.mk
include mk/help.mk
include mk/git.mk
include mk/push_swap.mk