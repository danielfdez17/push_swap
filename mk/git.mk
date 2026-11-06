# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    git.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 17:30:01 by danfern3          #+#    #+#              #
#    Updated: 2026/11/06 17:30:02 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ── Git

.PHONY: update-submodules
update-submodules: ## Update git submodules
	@$(PRINT_BANNER) "Updating Git Submodules"
	@git submodule update --init --recursive --remote
	@$(PRINT_SUCCESS) "Git submodules updated successfully!"
